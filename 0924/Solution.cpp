#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &graph, vector<int> &visited, int cur, int group, int &node_cnt) {
#if 0
        if (i < 0 || j < 0 || i >= graph.size() || j >= graph.size())
            return;
#endif
        if (visited[cur] >= 0)
            return;
        node_cnt ++;
        visited[cur] = group;
        for (int i = 0; i < graph[cur].size(); i ++) {
            if (!graph[cur][i])
                continue;
            dfs(graph, visited, i, group, node_cnt);
        }
    }

public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int node_sz = graph.size();
        vector<int> node2group(node_sz, -1);
        vector<int> group2node_cnt(node_sz, 0);
        vector<int> group2initial_cnt(node_sz, 0);
        int group = 0;
        int ans = initial[0];

        for (auto node : initial) {
            int cur_group = node2group[node];
            if (cur_group < 0) {
                cur_group = group;
                group ++;
                group2initial_cnt.push_back(1);
                dfs(graph, node2group, node, cur_group, group2node_cnt[cur_group]);
            }
            group2initial_cnt[cur_group] ++;
        }

        for (auto node : initial)
            ans = min(ans, node);

        for (auto node : initial) {
            int cur_group = node2group[node];
            if (group2initial_cnt[cur_group] > 1)
                continue;
            if (ans < 0)
                ans = node;
            else if (group2node_cnt[cur_group] > group2node_cnt[node2group[ans]])
                ans = node;
            else if (group2node_cnt[cur_group] == group2node_cnt[node2group[ans]] && node < ans)
                ans = node;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int node_sz = atoi(argv[1]);
    vector<vector<int>> graph(node_sz, vector<int>(node_sz));
    vector<int> initial;

    for (int i = 2; i < argc; i ++) {
        int n = atoi(argv[i]);
        initial.push_back(n);
    }

    for (int i = 0; i < node_sz; i ++) {
        for (int j = 0; j < node_sz; j ++) {
            cin >> graph[i][j];
        }
    }

    cout << solution.minMalwareSpread(graph, initial) << endl;

    return 0;
}
