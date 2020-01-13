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
    string removeOuterParentheses(string S) {
        int open = 0, n = S.size();
        string ans;

        for (auto c : S) {
            if (c == '(')
                open ++;
            else
                open --;

            if ((c == '(' && open > 1) ||
                (c == ')' && open > 0))
                ans.push_back(c);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);

    cout << solution.removeOuterParentheses(S) << endl;

    return 0;
}
