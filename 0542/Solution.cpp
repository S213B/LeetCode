#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        queue<pair<int, int>> queue;

        for (int i = 0; i < matrix.size(); i ++) {
            vector<int> row;
            for (int j = 0; j < matrix[i].size(); j ++) {
                if (matrix[i][j]) {
                    int val = -1;
                    if ((i && !matrix[i-1][j]) ||
                        (j && !matrix[i][j-1]) ||
                        (i < matrix.size()-1 && !matrix[i+1][j]) ||
                        (j < matrix[i].size()-1 && !matrix[i][j+1]))
                        val = 1;
                    row.push_back(val);
                    if (val == 1)
                        queue.push(make_pair(i, j));
                } else {
                    row.push_back(0);
                }
            }
            ans.push_back(row);
        }

        while (queue.size()) {
            int i = queue.front().first;
            int j = queue.front().second;
            queue.pop();
            if (i && ans[i-1][j] == -1) {
                ans[i-1][j] = ans[i][j] + 1;
                queue.push(make_pair(i-1, j));
            }
            if (j && ans[i][j-1] == -1) {
                ans[i][j-1] = ans[i][j] + 1;
                queue.push(make_pair(i, j-1));
            }
            if (i < matrix.size()-1 && ans[i+1][j] == -1) {
                ans[i+1][j] = ans[i][j] + 1;
                queue.push(make_pair(i+1, j));
            }
            if (j < matrix[i].size()-1 && ans[i][j+1] == -1) {
                ans[i][j+1] = ans[i][j] + 1;
                queue.push(make_pair(i, j+1));
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

    cout << endl;
    for (auto &r : grid) {
        for (auto nnn : r) {
            cout << nnn << " ";
        }
        cout << endl;
    }

    grid = solution.updateMatrix(grid);

    cout << endl;
    for (auto &r : grid) {
        for (auto nnn : r) {
            cout << nnn << " ";
        }
        cout << endl;
    }

    return 0;
}
