#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
private:
    bool dfs(int cur, vector<vector<int>> &graph, vector<int> &safe) {
        if (!graph[cur].size())
            return true;
        if (safe[cur] != -1)
            return safe[cur] != 0;
        safe[cur] = 0;
        for (int i = 0; i < graph[cur].size(); i ++) {
            int next = graph[cur][i];
            if (safe[next] == -1)
                safe[next] = dfs(next, graph, safe);
            if (!safe[next])
                return false;
        }
        safe[cur] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> safe(n, -1);

        for (int i = 0; i < n; i ++) {
            if (dfs(i, graph, safe))
                ans.push_back(i);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> graph;
    vector<int> row, ans;
    int n;

    while (cin >> n) {
        if (n == -1) {
            graph.push_back(row);
            row.clear();
        } else {
            row.push_back(n);
        }
    }

    ans = solution.eventualSafeNodes(graph);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
