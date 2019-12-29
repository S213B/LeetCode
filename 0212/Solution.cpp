#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    class node {
    public:
        node *next[26];
        string word;
        bool end;
        node () : end(false) {
            memset(next, 0, sizeof(next));
        }
        node *add(char c) {
            int i = c - 'a';
            if (!next[i])
                next[i] = new node();
            return next[i];
        }
        node *go(char c) {
            int i = c - 'a';
            return next[i];
        }
        void set_end(string &_word) {
            word = _word;
            end = true;
        }
    };

    void _findWords(vector<vector<char>> &board, int i, int j, node *n, vector<string> &ans) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
            return;
        char c = board[i][j];
        if (!c || !(n = n->go(c)))
            return;
        if (n->end) {
            ans.push_back(n->word);
            n->end = false;
        }
        board[i][j] = 0;
        _findWords(board, i+1, j, n, ans);
        _findWords(board, i-1, j, n, ans);
        _findWords(board, i, j+1, n, ans);
        _findWords(board, i, j-1, n, ans);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        node *root = new node();

        for (auto &word : words) {
            node *n = root;
            for (auto w : word)
                n = n->add(w);
            n->set_end(word);
        }

        for (int i = 0; i < board.size(); i ++)
            for (int j = 0; j < board[i].size(); j ++)
                _findWords(board, i, j, root, ans);

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
