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
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n2+1];
        int prev;

        dp[0] = 0;
        for (int i = 1; i < n2+1; i ++)
            dp[i] = i;

        for (int i = 1; i < n1+1; i ++) {
            dp[0] = i;
            prev = i-1;
            for (int j = 1; j < n2+1; j ++) {
                int t = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = prev;
                } else {
                    dp[j] += 1;
                    dp[j] = min(dp[j], dp[j-1] + 1);
                    dp[j] = min(dp[j], prev + 1);
                }
                prev = t;
            }
        }

        return dp[n2];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string word1(argv[1]);
    string word2(argv[2]);

    cout << solution.minDistance(word1, word2) << endl;

    return 0;
}
