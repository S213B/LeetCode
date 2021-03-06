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
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);
        vector<int> ans(N);

        for (auto &path : paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }

        for (int i = 0; i < N; i ++) {
            vector<bool> color(5, true);
            for (auto n : graph[i])
                color[ans[n]] = false;
            for (int j = 1; j < 5; j ++) {
                if (color[j])
                    ans[i] = j;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int N = atoi(argv[1]);
    vector<vector<int>> paths;
    vector<int> ans;
    int n;

    while (cin >> n) {
        vector<int> path;
        path.push_back(n);
        cin >> n;
        path.push_back(n);
        paths.push_back(path);
    }

    ans = solution.gardenNoAdj(N, paths);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
