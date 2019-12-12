#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& dis, int i, int j, int cur) {
        if (i < 0 || j < 0 || i >= dis.size() || j >= dis[i].size() || (cur && cur >= dis[i][j]))
            return;
        dis[i][j] = cur;
        dfs(dis, i+1, j, cur+1);
        dfs(dis, i, j+1, cur+1);
        dfs(dis, i-1, j, cur+1);
        dfs(dis, i, j-1, cur+1);
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int init_val = matrix.size() * matrix[0].size();

        for (int i = 0; i < matrix.size(); i ++) {
            vector<int> row;
            for (int j = 0; j < matrix[i].size(); j ++) {
                row.push_back(matrix[i][j] ? init_val : 0);
            }
            ans.push_back(row);
        }

        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                if (!matrix[i][j])
                    dfs(ans, i, j, 0);
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

    solution.updateMatrix(grid);

    cout << endl;
    for (auto &r : grid) {
        for (auto nnn : r) {
            cout << nnn << " ";
        }
        cout << endl;
    }

    return 0;
}
