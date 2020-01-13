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
        int ans = 0, level = 0;
        int n = S.size();

        for (int i = 0; i < n; i ++) {
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

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);

    cout << solution.scoreOfParentheses(S) << endl;

    return 0;
}
