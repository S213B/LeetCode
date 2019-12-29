#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WordDictionary {
private:
    class node {
    public:
        node *next[26];
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
        node *get(char c) {
            int i = c - 'a';
            return next[i];
        }
    };

    node *root;

    bool _search(node *n, string &word, int i) {
        if (i >= word.size())
            return n->end;
        while (i < word.size()) {
            if (word[i] != '.') {
                n = n->get(word[i]);
                if (!n)
                    return false;
            } else {
                for (char j = 'a'; j <= 'z'; j ++) {
                    node *nn = n->get(j);
                    if (nn && _search(nn, word, i+1))
                        return true;
                }
                return false;
            }
            i ++;
        }
        return n->end;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *n = root;
        for (auto c : word) {
            n = n->add(c);
        }
        n->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return _search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char *argv[]) {
    WordDictionary dict;
    string cmd, str;

    while (cin >> cmd) {
        bool r = true;
        cin >> str;
        if (!cmd.compare("add"))
            dict.addWord(str);
        else if (!cmd.compare("search"))
            r = dict.search(str);
        cout << r << endl;
    }

    return 0;
}
