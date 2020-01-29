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
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;

        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (board[i][j] == '.')
                    continue;
                if (i && board[i-1][j] == 'X')
                    continue;
                if (j && board[i][j-1] == 'X')
                    continue;
                ans ++;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int row_sz = atoi(argv[1]);
    vector<vector<char>> board;
    vector<char> row;
    char c;

    while (cin >> c) {
        row.push_back(c);
        if (row.size() == row_sz) {
            board.push_back(row);
            row.clear();
        }
    }

    cout << solution.countBattleships(board) << endl;

    return 0;
}
