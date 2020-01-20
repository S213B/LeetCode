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
    void bfs(vector<int> &ans, vector<vector<int>> &red, vector<vector<int>> &blue, bool from_red) {
        queue<int> q;
        vector<vector<int>> *edges = from_red ? &red : &blue;
        vector<bool> red_visited(ans.size()), blue_visited(ans.size());
        vector<bool> *visited = from_red ? &red_visited : &blue_visited;
        int step = 1;

        (*visited)[0] = true;
        q.push(0);

        while (q.size()) {
            int q_sz = q.size();
            from_red = !from_red;
            edges = from_red ? &red : &blue;
            visited = from_red ? &red_visited : &blue_visited;
            for (int i = 0; i < q_sz; i ++) {
                int curr = q.front();
                q.pop();
                for (auto next : (*edges)[curr]) {
                    if ((*visited)[next])
                        continue;
                    (*visited)[next] = true;
                    q.push(next);
                    if (ans[next] == -1 || step < ans[next])
                        ans[next] = step;
                }
            }
            step ++;
        }
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ans(n, -1);
        vector<vector<int>> red(n), blue(n);

        for (auto &e : red_edges)
            red[e[0]].push_back(e[1]);
        for (auto &e : blue_edges)
            blue[e[0]].push_back(e[1]);

        ans[0] = 0;
        bfs(ans, red, blue, true);
        bfs(ans, red, blue, false);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);
    int red_edges_sz = atoi(argv[2]);
    int blue_edges_sz = atoi(argv[3]);
    vector<vector<int>> red_edges, blue_edges;
    vector<int> ans;

    for (int i = 0; i < red_edges_sz; i ++) {
        int n1, n2;
        vector<int> e;
        cin >> n1;
        cin >> n2;
        e.push_back(n1);
        e.push_back(n2);
        red_edges.push_back(e);
    }

    for (int i = 0; i < blue_edges_sz; i ++) {
        int n1, n2;
        vector<int> e;
        cin >> n1;
        cin >> n2;
        e.push_back(n1);
        e.push_back(n2);
        blue_edges.push_back(e);
    }

    ans = solution.shortestAlternatingPaths(n, red_edges, blue_edges);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
