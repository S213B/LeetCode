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
    bool is_palindrome(string &str, int s, int e) {
        while (s < e) {
            if (str[s] != str[e])
                return false;
            s ++;
            e --;
        }
        return true;
    }

    struct node {
        unordered_map<char, struct node *> next;
        vector<int> words;
        int done;
        node() : done(-1) {};
    };

    struct node *add_node(struct node *n, char c, int i) {
        if (!n->next[c]) {
            n->next[c] = new node();
        }
        n->words.push_back(i);
        return n->next[c];
    }

    struct node root;

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i ++) {
            struct node *n = &root;
            for (auto c : words[i]) {
                n = add_node(n, c, i);
            }
            n->done = i;
        }

        for (int i = 0; i < words.size(); i ++) {
            struct node *n = &root;
            for (int j = words[i].size()-1; n && j >= 0; j --) {
                if (n->done >=0 && is_palindrome(words[i], 0, j)) {
                    ans.push_back({n->done, i});
                }
                n = n->next[words[i][j]];
            }
            if (!n)
                continue;
            if (n->done >= 0 && i != n->done)
                ans.push_back({n->done, i});
            for (auto j : n->words) {
                if (is_palindrome(words[j], words[i].size(), words[j].size()-1)) {
                    ans.push_back({j, i});
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words;
    vector<vector<int>> ans;
    string word;

    while (cin >> word)
        words.push_back(word);

    ans = solution.palindromePairs(words);

    for (auto &an : ans)
        cout << an[0] << ',' << an[1] << endl;

    return 0;
}
