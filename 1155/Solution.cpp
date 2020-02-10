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
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target+1), prev(target+1);
        int mod = 1000000007;

        for (int i = 1; i <= f && i <= target; i ++)
            prev[i] = 1;

        for (int i = 1; i < d; i ++) {
            for (int j = i+1; j <= target; j ++) {
                for (int k = 1; k <= f; k ++) {
                    if (j < k)
                        continue;
                    dp[j] += prev[j-k];
                    dp[j] %= mod;
                }
            }
            prev = dp;
            fill(dp.begin(), dp.end(), 0);
        }

        return prev[target];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int d = atoi(argv[1]);
    int f = atoi(argv[2]);
    int target = atoi(argv[3]);

    cout << solution.numRollsToTarget(d, f, target) << endl;

    return 0;
}
