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
        char val;
        bool skip, loop;
        node *next;
        node() {
            val = '\0';
            next = nullptr;
            skip = loop = false;
        }
    };

    void add_pattern(node *root, string &p) {
        node *n = root;
        for (char c : p) {
            if (n->loop && c == '*')
                continue;
            n->next = new node;
            n = n->next;
            if (c == '*') {
                n->loop = true;
            } else if (c == '?') {
                n->skip = true;
            } else {
                n->val = c;
            }
        }
    }

    class state {
    public:
        node *cur_node;
        int cur_idx;
        state(node *n, int i) {
            cur_idx = i;
            cur_node = n;
        }
    };

    bool match_pattern(node *root, string s) {
        vector<state *> stack;
        state *st;
        node *n = root->next;
        int si = 0;

        while (true) {
            if (si == s.size()) {
                while (n && n->loop) n = n->next;
                if (!n)
                    return true;
            }
            if (si == s.size() || !n) {
                if (!stack.size())
                    return false;
                st = stack.back();
                stack.pop_back();
                si = st->cur_idx;
                n = st->cur_node;
            }

            int c = s[si];
            if (n->skip) {
                n = n->next;
            } else if (n->loop) {
                if (si+1 < s.size()) {
                    st = new state(n, si+1);
                    stack.push_back(st);
                }
                if (n->next) {
                    st = new state(n->next, si);
                    stack.push_back(st);
                }
                n = n->next;
            } else {
                if (n->val == c)
                    n = n->next;
                else
                    si = s.size()-1;    //fail
            }
                si ++;
        }

        return false;
    }

    bool prematch(string &s, string &p) {
        for (int i = 0, j = 0; i < p.size() && p[i] != '*'; i++) {
            if (j >= s.size() || (p[i] != '?' && p[i] != s[j]))
                return false;
            j ++;
        }

        for (int i = p.size()-1, j = s.size()-1; i >=0 && p[i] != '*'; i--) {
            if (j < 0 || (p[i] != '?' && p[i] != s[j]))
                return false;
            j --;
        }

        for (int i = 0, si = 0; i < p.size(); ) {
            while (i < p.size() && (p[i] == '*' || p[i] == '?')) {
                if (p[i] == '?')
                    si ++;
                i ++;
            }
            int j = i + 1;
            while (j < p.size() && p[j] != '*' && p[j] != '?') j ++;
            size_t new_si = s.find(p.substr(i, j-i), si);
            if (new_si == string::npos)
                return false;
            si = new_si + (j - i);
            i = j;
        }

        return true;
    }

public:
    bool isMatch(string s, string p) {
        node *root = new node;

        if (!prematch(s, p))
            return false;

        add_pattern(root, p);

        return match_pattern(root, s);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    string p(argv[2]);

    cout << solution.isMatch(s, p) << endl;

    return 0;
}
