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
    int uniquePaths(int m, int n) {
        vector<int> dp(n);

        for (int i = 0; i < m; i ++) {
            dp[0] = 1;
            for (int j = 1; j < n; j ++) {
                dp[j] = dp[j-1] + dp[j];
            }
        }

        return dp.back();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int m = atoi(argv[1]), n = atoi(argv[2]);

    cout << solution.uniquePaths(m, n) << endl;

    return 0;
}
