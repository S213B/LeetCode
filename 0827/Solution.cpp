#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (grid[i][j] != 1)
            return 0;
        int sz = 1;
        grid[i][j] = id;
        if (i)
            sz += dfs(grid, i-1, j, id);
        if (j)
            sz += dfs(grid, i, j-1, id);
        if (i < grid.size()-1)
            sz += dfs(grid, i+1, j, id);
        if (j < grid[i].size()-1)
            sz += dfs(grid, i, j+1, id);
        return sz;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        const int id_ofst = 2;
        vector<int> id2sz;
        int v[4];

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == 1) {
                    int sz = dfs(grid, i, j, id2sz.size() + id_ofst);
                    ans = max(ans, sz);
                    id2sz.push_back(sz);
                }
            }
        }

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == 0) {
                    memset(v, 0, sizeof(v));
                    if (i)
                        v[0] = grid[i-1][j];
                    if (j)
                        v[1] = grid[i][j-1];
                    if (i < grid.size()-1)
                        v[2] = grid[i+1][j];
                    if (j < grid[i].size()-1)
                        v[3] = grid[i][j+1];
                    int tmp_ans = 1;
                    for (int k = 0; k < 4; k ++) {
                        if (v[k] < id_ofst)
                            continue;
                        bool is_dup = false;
                        for (int l = k - 1; l >= 0; l --) {
                            if (v[l] == v[k])
                                is_dup = true;
                        }
                        if (is_dup)
                            continue;
                        tmp_ans += id2sz[v[k] - id_ofst];
                    }
                    ans = max(ans, tmp_ans);
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;
    vector<int> row;
    int n = atoi(argv[1]);
    int nn;

    while (cin >> nn) {
        row.push_back(nn);
        if (row.size() == n) {
            grid.push_back(row);
            row.clear();
        }
    }

    for (auto &r : grid) {
        for (auto nnn : r) {
            cout << nnn << " ";
        }
        cout << endl;
    }

    cout << solution.largestIsland(grid) << endl;

    return 0;
}
