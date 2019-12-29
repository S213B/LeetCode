#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool find(vector<vector<char>> &board, int i, int j, string &word, int k) {
        if (k >= word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
            return false;
        if (board[i][j] != word[k])
            return false;
        bool match = false;
        board[i][j] = 0;
        match = find(board, i+1, j, word, k+1) |
                find(board, i-1, j, word, k+1) |
                find(board, i, j+1, word, k+1) |
                find(board, i, j-1, word, k+1);
        board[i][j] = word[k];
        return match;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        for (auto &word : words) {
            bool match = false;
            for (int i = 0; i < board.size() && !match; i ++) {
                for (int j = 0; j < board[i].size(); j ++) {
                    if (find(board, i, j, word, 0)) {
                        match = true;
                        break;
                    }
                }
            }
            if (match)
                ans.push_back(word);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<char>> board;
    vector<char> row;
    vector<string> words;
    vector<string> ans;
    int row_sz = atoi(argv[1]);
    char c;

    for (int i = 2; i < argc; i ++) {
        string word(argv[i]);
        words.push_back(word);
    }

    while (cin >> c) {
        row.push_back(c);
        if (row.size() >= row_sz) {
            board.push_back(row);
            row.clear();
        }
    }

    ans = solution.findWords(board, words);

    for (auto &an : ans)
        cout << an << endl;

    return 0;
}
