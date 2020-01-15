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
private:
    int helper(int d, int f, int target, vector<vector<int>> &memo) {
        if (!d && !target)
            return 1;
        if (d <= 0 || target <= 0)
            return 0;
        if (memo[d][target] >= 0)
            return memo[d][target];
        memo[d][target] = 0;
        for (int i = 1; i <= f; i ++) {
            memo[d][target] += helper(d-1, f, target-i, memo);
            memo[d][target] %= 1000000007;
        }
        return memo[d][target];
    }

public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> memo(d+1, vector<int>(target+1, -1));

        if (d <= 0 || target <= 0)
            return 0;

        return helper(d, f, target, memo);
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
