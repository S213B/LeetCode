#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Trie {
private:
    class node {
    public:
        node *next[26];
        bool end;
        node() : end(false) {
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
        void set_end(void) {
            end = true;
        }
        bool is_end(void) {
            return end;
        }
    };

    node *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node *n = root;
        for (auto c : word) {
            n = n->add(c);
        }
        n->set_end();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *n = root;
        for (auto c : word) {
            n = n->go(c);
            if (!n)
                return false;
        }
        return n->is_end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *n = root;
        for (auto c : prefix) {
            n = n->go(c);
            if (!n)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char *argv[]) {
    Trie trie;
    string cmd, str;

    while (cin >> cmd) {
        bool r = true;
        cin >> str;
        if (!cmd.compare("insert"))
            trie.insert(str);
        else if (!cmd.compare("search"))
            r = trie.search(str);
        else if (!cmd.compare("start"))
            r = trie.startsWith(str);
        cout << r << endl;
    }

    return 0;
}
