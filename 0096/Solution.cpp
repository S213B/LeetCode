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
    int numTrees(int n) {
        if (!n)
            return 0;
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i < n+1; i ++) {
            for (int j = 0; j <= i-1; j ++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);

    cout << solution.numTrees(n) << endl;

    return 0;
}
