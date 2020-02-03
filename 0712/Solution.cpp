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
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n2+1];
        int dp_i1j1;

        dp[0] = 0;
        for (int j = 1; j < n2+1; j ++)
            dp[j] = dp[j-1] + s2[j-1];

        for (int i = 1; i < n1+1; i ++) {
            dp_i1j1 = dp[0];
            dp[0] += s1[i-1];
            for (int j = 1; j < n2+1; j ++) {
                int t = dp[j];
                if (s1[i-1] == s2[j-1]) {
                    dp[j] = dp_i1j1;
                } else {
                    dp[j] += s1[i-1];
                    dp[j] = min(dp[j], dp_i1j1 + s1[i-1] + s2[j-1]);
                    dp[j] = min(dp[j], dp[j-1] + s2[j-1]);
                }
                dp_i1j1 = t;
            }
        }

        return dp[n2];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.minimumDeleteSum(s1, s2) << endl;

    return 0;
}
