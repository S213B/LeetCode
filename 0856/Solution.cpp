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
    int scoreOfParentheses(string S) {
        stack<int> stk;

        for (auto c : S) {
            if (c == '(') {
                stk.push(-1);
            } else {
                int v = 1;
                if (stk.top() == -1) {
                    stk.pop();
                } else {
                    v = stk.top() * 2;
                    stk.pop();
                    stk.pop();
                }
                if (stk.size() && stk.top() > 0) {
                    v += stk.top();
                    stk.pop();
                }
                stk.push(v);
            }
        }

        return stk.top();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);

    cout << solution.scoreOfParentheses(S) << endl;

    return 0;
}
