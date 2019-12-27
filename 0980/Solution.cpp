#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print_grid(vector<vector<int>>& grid) {
    for (auto &row : grid) {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }
}

/*
 * 1: start
 * 2: end
 * 0: good to go
 * -1: obstacle
 */
class Solution {
private:
    bool cover_all(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (!grid[i][j])
                    return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int &ans) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return;
        if (grid[i][j]) {
            if (grid[i][j] == 2 && cover_all(grid))
                ans ++;
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i+1, j, ans);
        dfs(grid, i-1, j, ans);
        dfs(grid, i, j+1, ans);
        dfs(grid, i, j-1, ans);
        grid[i][j] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int si = -1, sj = -1;

        for (int i = 0; i < grid.size() && si == -1; i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                    break;
                }
            }
        }

        dfs(grid, si+1, sj, ans);
        dfs(grid, si-1, sj, ans);
        dfs(grid, si, sj+1, ans);
        dfs(grid, si, sj-1, ans);

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
        if (row.size() == row_sz) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << solution.uniquePathsIII(grid) << endl;

    return 0;
}
