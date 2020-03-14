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
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int ans = 0;

        if (A.size() < 2)
            return A.size();

        for (int i = 1; i < A.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                int diff = A[i] - A[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;

    for (int i = 1; i < argc; i ++)
        A.push_back(atoi(argv[i]));

    cout << solution.longestArithSeqLength(A) << endl;

    return 0;
}
