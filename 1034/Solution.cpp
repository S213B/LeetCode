#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool is_border(vector<vector<int>>& grid, int r, int c) {
        if (!r || !c || r == grid.size()-1 || c == grid[r].size()-1)
            return true;
        if (grid[r+1][c] > 0 && grid[r][c] != grid[r+1][c])
            return true;
        if (grid[r][c+1] > 0 && grid[r][c] != grid[r][c+1])
            return true;
        if (grid[r-1][c] > 0 && grid[r][c] != grid[r-1][c])
            return true;
        if (grid[r][c-1] > 0 && grid[r][c] != grid[r][c-1])
            return true;
        return false;
    }

    bool is_out(vector<vector<int>>& grid, int r, int c, int ori) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size())
            return true;
        if (grid[r][c] != ori)
            return true;
        return false;
    }

    void _colorBorder(vector<vector<int>>& grid, int r, int c, int ori) {
        if (is_out(grid, r, c, ori))
            return;
        if (is_border(grid, r, c))
            grid[r][c] = -1;
        else
            grid[r][c] = -2;
        _colorBorder(grid, r+1, c, ori);
        _colorBorder(grid, r-1, c, ori);
        _colorBorder(grid, r, c+1, ori);
        _colorBorder(grid, r, c-1, ori);
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid[r0][c0] == color)
            return grid;

        int ori = grid[r0][c0];

        _colorBorder(grid, r0, c0, grid[r0][c0]);

        for (auto &row : grid) {
            for (auto &ele : row) {
                if (ele > 0)
                    continue;
                ele = (ele == -1) ? color : ori;
            }
        }

        return grid;
    }
};

static void print_grid(vector<vector<int>> &grid) {
    for (auto row : grid) {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    Solution solution;
    int row_sz = atoi(argv[1]);
    int r0 = atoi(argv[2]);
    int c0 = atoi(argv[3]);
    int color = atoi(argv[4]);
    int in;
    vector<vector<int>> grid, ans;
    vector<int> row;

    while (cin >> in) {
        row.push_back(in);
        if (row.size() == row_sz) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << "before:" << endl;
    print_grid(grid);

    ans = solution.colorBorder(grid, r0, c0, color);

    cout << "after:" << endl;
    print_grid(grid);

    return 0;
}
