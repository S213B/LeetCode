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
    void dfs(string &s, int i, string &an, int open, int del_open, int del_close, unordered_set<string> &ans) {
        if (i == s.size()) {
            if (!del_open && !del_close)
                ans.insert(an);
            return;
        }
        char ch = s[i];
        if (ch == '(') {
            if (del_open)
                dfs(s, i+1, an, open, del_open-1, del_close, ans);
            an.push_back(ch);
            dfs(s, i+1, an, open+1, del_open, del_close, ans);
            an.pop_back();
        } else if (ch == ')') {
            if (del_close)
                dfs(s, i+1, an, open, del_open, del_close-1, ans);
            if (open) {
                an.push_back(ch);
                dfs(s, i+1, an, open-1, del_open, del_close, ans);
                an.pop_back();
            }
        } else {
            an.push_back(ch);
            dfs(s, i+1, an, open, del_open, del_close, ans);
            an.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int del_open = 0, del_close = 0, open = 0;
        unordered_set<string> ans;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(')
                open ++;
            else if (s[i] == ')')
                open --;
            if (open < 0) {
                del_close ++;
                open ++;
            }
        }
        del_open = open;

        string an;
        dfs(s, 0, an, 0, del_open, del_close, ans);

        return vector<string>(ans.begin(), ans.end());
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    vector<string> ans;

    ans = solution.removeInvalidParentheses(s);

    for (auto &an : ans)
        cout << an << endl;

    return 0;
}
