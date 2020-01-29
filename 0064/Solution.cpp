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
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &dis, int i, int j, int sum, int &ans) {
        if (i >= grid.size() || j >= grid[i].size())
            return -1;
        if (i == grid.size()-1 && j == grid[i].size()-1) {
            ans = min(ans, sum + grid[i][j]);
            return grid[i][j];
        }
        if (dis[i][j] < 0) {
            int r1 = dfs(grid, dis, i+1, j, sum+grid[i][j], ans);
            int r2 = dfs(grid, dis, i, j+1, sum+grid[i][j], ans);
            dis[i][j] = r1 < 0 ? r2 : r2 < 0 ? r1 : min(r1, r2);
            dis[i][j] += grid[i][j];
        }
        sum += dis[i][j];
        ans = min(ans, sum);
        return dis[i][j];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));

        dfs(grid, dis, 0, 0, 0, ans);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int row_sz = atoi(argv[1]), n;
    vector<vector<int>> grid;
    vector<int> row;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() == row_sz) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << solution.minPathSum(grid) << endl;

    return 0;
}
