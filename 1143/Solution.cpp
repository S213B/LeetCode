#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001] = {0};

        dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;
        for (int i = 1; i < text2.size(); i ++)
            dp[0][i] = (text1[0] == text2[i]) ? 1 : dp[0][i-1];
        for (int i = 1; i < text1.size(); i ++)
            dp[i][0] = (text1[i] == text2[0]) ? 1 : dp[i-1][0];

        for (int i = 1; i < text1.size(); i ++) {
            for (int j = 1; j < text2.size(); j ++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()-1][text2.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string text1(argv[1]);
    string text2(argv[2]);

    cout << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
