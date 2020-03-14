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
    int water_cnt(vector<vector<int>> &grid, int i, int j) {
        int cnt = 0;
        if (!i || !grid[i-1][j])
            cnt ++;
        if (!j || !grid[i][j-1])
            cnt ++;
        if (i == grid.size()-1 || !grid[i+1][j])
            cnt ++;
        if (j == grid[i].size()-1 || !grid[i][j+1])
            cnt ++;
        return cnt;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (!grid[i][j])
                    continue;
                ans += water_cnt(grid, i, j);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;
    vector<int> row;
    int col = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() >= col) {
            grid.push_back(row);
            row.clear();
        }
    }

    cout << solution.islandPerimeter(grid) << endl;

    return 0;
}
