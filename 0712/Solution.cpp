#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> dp(s2.size(), 0);

        dp[0] = (s1[0] == s2[0]) ? 0 : (s1[0] + s2[0]);
        for (int i = 1, acc = s2[0]; i < s2.size(); i ++) {
            dp[i] = (s1[0] == s2[i]) ? acc : dp[i-1] + s2[i];
            acc += s2[i];
        }

        for (int i = 1, acc = s1[0]; i < s1.size(); i ++) {
            int prev = dp[0];
            dp[0] = (s1[i] == s2[0]) ? acc : dp[0] + s1[i];
            acc += s1[i];
            for (int j = 1; j < s2.size(); j ++) {
                int _prev = dp[j];
                if (s1[i] == s2[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] += s1[i];
                    dp[j] = min(dp[j], prev + s1[i] + s2[j]);
                    dp[j] = min(dp[j], dp[j-1] + s2[j]);
                }
                prev = _prev;
            }
        }

        return dp[s2.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.minimumDeleteSum(s1, s2) << endl;

    return 0;
}
