#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool _exist(vector<vector<char>>& board, int x, int y, string &word, int cur) {
        if (cur == word.size() - 1)
            return true;
        int next = cur + 1;
        if (x && board[x-1][y] == word[next]) {
            board[x-1][y] = 0;
            if (_exist(board, x-1, y, word, next))
                return true;
            board[x-1][y] = word[next];
        }
        if (y && board[x][y-1] == word[next]) {
            board[x][y-1] = 0;
            if (_exist(board, x, y-1, word, next))
                return true;
            board[x][y-1] = word[next];
        }
        if (x < board.size()-1 && board[x+1][y] == word[next]) {
            board[x+1][y] = 0;
            if (_exist(board, x+1, y, word, next))
                return true;
            board[x+1][y] = word[next];
        }
        if (y < board[x].size()-1 && board[x][y+1] == word[next]) {
            board[x][y+1] = 0;
            if (_exist(board, x, y+1, word, next))
                return true;
            board[x][y+1] = word[next];
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    char t = board[i][j];
                    board[i][j] = 0;
                    if (_exist(board, i, j, word, 0))
                        return true;
                    board[i][j] = t;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
