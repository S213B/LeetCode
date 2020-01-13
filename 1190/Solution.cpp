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
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string ans;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                reverse(s.begin() + stk.top(), s.begin() + i + 1);
                stk.pop();
            }
        }

        for (auto c : s) {
            if (c != '(' && c != ')')
                ans.push_back(c);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.reverseParentheses(s) << endl;

    return 0;
}
