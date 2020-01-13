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
        vector<int> peer(s.size(), -1);
        stack<int> stk;
        string ans;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                peer[stk.top()] = i;
                peer[i] = stk.top();
                stk.pop();
            }
        }

        for (int i = 0, dir = 1; i < s.size(); i += dir) {
            if (peer[i] == -1) {
                ans.push_back(s[i]);
            } else {
                i = peer[i];
                dir = -dir;
            }
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
