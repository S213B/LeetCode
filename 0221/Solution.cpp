#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool can_grow(vector<vector<char>>& matrix, int i, int j, int cur_sz) {
        if (i + cur_sz >= matrix.size())
            return false;
        if (j + cur_sz >= matrix[0].size())
            return false;
        for (int k = 0; k <= cur_sz; k ++)
            if (matrix[i + cur_sz][j + k] == '0' ||
                matrix[i + k][j + cur_sz] == '0')
                return false;
        return true;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> last_row(matrix.size() ? matrix[0].size() : 0, 0);
        int last_col = 0;
        int ans = 0;

        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                int cur_sz = max(last_row[j] - 1, last_col - 1);
                cur_sz = max(0, cur_sz);
                while (can_grow(matrix, i, j, cur_sz))
                    cur_sz ++;
                ans = max(ans, cur_sz);
                last_col = cur_sz;
                last_row[j] = cur_sz;
            }
        }

        return ans * ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> matrix;
    vector<char> row;
    int row_sz = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n ? '1' : '0');
        if (row.size() == row_sz) {
            matrix.push_back(row);
            row.clear();
        }
    }

    cout << endl;
    cout << solution.maximalSquare(matrix) << endl;

    return 0;
}
