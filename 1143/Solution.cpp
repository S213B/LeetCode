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
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size()+1);

        for (int i = 1; i <= text1.size(); i ++) {
            int prev = 0;
            for (int j = 1; j <= text2.size(); j ++) {
                int t = dp[j];
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = t;
            }
        }

        return dp[text2.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string text1(argv[1]);
    string text2(argv[2]);

    cout << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
