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
    int minPathSum(vector<vector<int>>& grid) {
        if (!grid.size())
            return 0;

        vector<int> dp(grid[0].size(), INT_MAX);

        dp[0] = 0;
        for (int i = 0; i < grid.size(); i ++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < grid[i].size(); j ++) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }

        return dp.back();
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
