#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
private:
    void helper(vector<string> &v, int n) {
        unordered_set<string> set;

        if (!n) {
            v.push_back("");
            return;
        }

        helper(v, n-1);

        for (auto &s : v) {
            for (int i = 0; i <= s.size(); i++) {
                string ss(s);
                ss.insert(ss.begin() + i, '(');
                for (int j = i+1; j <= ss.size(); j++) {
                    string sss(ss);
                    sss.insert(sss.begin() + j, ')');
                    set.insert(sss);
                }
            }
        }

        v.clear();
        v.assign(set.begin(), set.end());
    }

public:
    vector<string> go(int n) {
        vector<string> ans;
        unordered_set<string> set;
        string ori;

#if 0
        helper(ans, n);
#else
        for (int i = 0; i < n; i++)
            ori.append("()");
        ans.push_back(ori);

        for (int i = 1; i < ori.size(); i++) {
            int ans_sz = ans.size();
            for (int s_idx = 0; s_idx < ans.size(); s_idx++) {
                string s = ans[s_idx];
                if (s[i] == '(')
                    continue;
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] == ')')
                        continue;
                    string ss(s.begin(), s.end());
                    char t = ss[i];
                    ss[i] = ss[j];
                    ss[j] = t;
                    if (set.find(ss) == set.end()) {
                        set.insert(ss);
                        ans.push_back(ss);
                    }
                }
            }
        }
#endif

        return ans;
    }
};

bool is_pair(char a, char b) {
    return a == '(' && b == ')';
}

bool is_valid(string &s) {
    stack<char> stack;

    for (auto c : s) {
        if (stack.size() && is_pair(stack.top(), c)) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    return stack.empty();
}

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> v;

    for (int i = 9; i < atoi(argv[1]); i++) {
        v = solution.go(i);

        for (auto &s : v) {
            if (!is_valid(s)) {
                cout << s << endl;
                break;
            }
        }
    }

    return 0;
}
