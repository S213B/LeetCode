#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return 0;
        if (!grid[i][j])
            return 0;
        int rc = 1;
        grid[i][j] = 0;
        rc += dfs(grid, i+1, j);
        rc += dfs(grid, i-1, j);
        rc += dfs(grid, i, j+1);
        rc += dfs(grid, i, j-1);
        return rc;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size();j ++) {
                if (!grid[i][j])
                    continue;
                int sz = dfs(grid, i, j);
                ans = max(ans, sz);
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;
    vector<int> row;
    int row_sz = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() >= row_sz) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << solution.maxAreaOfIsland(grid) << endl;

    return 0;
}
