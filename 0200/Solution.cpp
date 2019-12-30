#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == '0')
                    continue;
                ans ++;
                dfs(grid, i, j);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> grid;
    vector<char> row;
    int row_sz = atoi(argv[1]);
    char c;

    while (cin >> c) {
        row.push_back(c);
        if (row.size() >= row_sz) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << solution.numIslands(grid) << endl;

    return 0;
}
