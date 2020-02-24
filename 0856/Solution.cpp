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

#if 0
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;

        for (auto s : S) {
            int c = (s == '(') ? -1 : -2;
            if (c == -2) {
                if (stk.top() == -1) {
                    c = 1;
                } else if (stk.top() > 0) {
                    c = stk.top() * 2;
                    stk.pop();
                }
                stk.pop();
                if (stk.size() && stk.top() > 0) {
                    c += stk.top();
                    stk.pop();
                }
            }
            stk.push(c);
        }

        return stk.size() ? stk.top() : 0;
    }
};
#else
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, level = 0;

        for (int i = 0; i < S.size(); i ++) {
            if (S[i] == '(')
                level ++;
            else
                level --;
            if (S[i] == ')' && S[i-1] == '(')
                ans += 1 << level;
        }

        return ans;
    }
};
#endif

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);

    cout << solution.scoreOfParentheses(S) << endl;

    return 0;
}
