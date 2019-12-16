#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MapSum {
private:
    class trie {
    public:
        trie *next[128];
        int val;
        trie(void) {
            memset(next, 0, sizeof(next));
            val = 0;
        }
        trie *add(char idx, int val) {
            if (!next[idx])
                next[idx] = new trie();
            next[idx]->val += val;
            return next[idx];
        }
        trie *go(char idx) {
            return next[idx];
        }
    };

    trie root;
    unordered_map<string, int> map;

public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        int v = val - map[key];
        map[key] = val;
        trie *n = &root;
        for (auto c : key) {
            n = n->add(c, v);
        }
    }

    int sum(string prefix) {
        trie *n = &root;
        for (auto c : prefix) {
            n = n->go(c);
            if (!n)
                return 0;
        }
        return n->val;
    }
};

int main(int argc, char *argv[]) {
    MapSum mapsum;
    string cmd, key, prefix;
    int val;

    while (cin >> cmd) {
        if (!cmd.compare("insert")) {
            cin >> key;
            cin >> val;
            mapsum.insert(key, val);
        } else if (!cmd.compare("sum")) {
            cin >> prefix;
            cout << mapsum.sum(prefix) << endl;
        }
    }

    return 0;
}
