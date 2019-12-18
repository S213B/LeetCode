#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#if 0
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

#else

class Solution {
private:
    vector<string> split_pat(string &p) {
        vector<string> pat;
        int i = 0, j = 0;
        while (i < p.size()) {
            if (p[i] == '*') {
                pat.push_back(p.substr(j, i - j));
                j = i + 1;
            }
            i ++;
        }
        pat.push_back(p.substr(j, i - j));
        return pat;
    }

    bool ch_match(char s, char p) {
        return p == '?' || s == p;
    }

    bool match_begin(string &s, string &p) {
        int si = 0;
        for (int i = 0; i < p.size(); i ++) {
            if (si < s.size() && ch_match(s[si], p[i]))
                si ++;
            else
                return false;
        }
        return true;
    }

    bool match_mid(string &s, vector<string> &p) {
        int si = 0;
        for (int i = 0; i < p.size(); i ++) {
            if (!p[i].size())
                continue;
            int match = 0;
            while (si < s.size()) {
                int j = 0, ori_si = si;
                while (j < p[i].size() && si < s.size() && ch_match(s[si], p[i][j])) {
                    j ++;
                    si ++;
                }
                if (j == p[i].size()) {
                    match = 1;
                    break;
                }
                si = ori_si + 1;
            }
            if (!match)
                return false;
        }
        return true;
    }

public:
    bool isMatch(string s, string p) {
        vector<string> pat;

        if (!p.size()) {
            if (s.size())
                return false;
            else
                return true;
        }

        pat = split_pat(p);

        if (pat.size() == 1 && s.size() != pat[0].size())
            return false;
        if (!match_begin(s, pat[0]))
            return false;
        s = s.substr(pat[0].size());
        pat.erase(pat.begin());

        if (pat.size()) {
            reverse(s.begin(), s.end());
            reverse(pat.back().begin(), pat.back().end());
            if (!match_begin(s, pat.back()))
                return false;
            s = s.substr(pat.back().size());
            pat.pop_back();
            reverse(s.begin(), s.end());
        }

        return match_mid(s, pat);
    }
};
#endif

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    string p(argv[2]);

    cout << solution.isMatch(s, p) << endl;

    return 0;
}
