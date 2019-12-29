#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001] = {0};
        
        dp[0][0] = (s1[0] == s2[0]) ? 0 : (s1[0] + s2[0]);
        for (int i = 1, acc = s2[0]; i < s2.size(); i ++) {
            dp[0][i] = (s1[0] == s2[i]) ? acc : dp[0][i-1] + s2[i];
            acc += s2[i];
        }
        for (int i = 1, acc = s1[0]; i < s1.size(); i ++) {
            dp[i][0] = (s1[i] == s2[0]) ? acc : dp[i-1][0] + s1[i];
            acc += s1[i];
        }

        for (int i = 1; i < s1.size(); i ++) {
            for (int j = 1; j < s2.size(); j ++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] + s1[i] + s2[j];
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + s1[i]);
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + s2[j]);
                }
            }
        }

        return dp[s1.size()-1][s2.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.minimumDeleteSum(s1, s2) << endl;

    return 0;
}
