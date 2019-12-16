#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool blk[9][9];

    bool _solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; k ++) {
                        if (!row[i][k] && !col[j][k] && !blk[(i/3)*3+j/3][k]) {
                            row[i][k] = true;
                            col[j][k] = true;
                            blk[(i/3)*3+j/3][k] = true;
                            board[i][j] = '0' + k + 1;
                            if (_solveSudoku(board))
                                return true;
                            row[i][k] = false;
                            col[j][k] = false;
                            blk[(i/3)*3+j/3][k] = false;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(blk, 0, sizeof(blk));

        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    row[i][idx] = true;
                    col[j][idx] = true;
                    blk[(i/3)*3+j/3][idx] = true;
                }
            }
        }

        _solveSudoku(board);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> board;
    vector<char> row;
    int num;

    while (cin >> num) {
        char ch;
        if (num == 0)
            ch = '.';
        else
            ch = '0' + num;
        row.push_back(ch);
        if (row.size() == 9) {
            board.push_back(row);
            if (board.size() == 9)
                break;
            row.clear();
        }
    }

    solution.solveSudoku(board);

    for (auto &r: board) {
        for (auto n : r)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
