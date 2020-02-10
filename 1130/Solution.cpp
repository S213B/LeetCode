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
    int mctFromLeafValues(vector<int>& arr) {
        int arr_sz = arr.size();
        vector<vector<int>> dp(arr_sz, vector<int>(arr_sz, INT_MAX));
        vector<vector<int>> peak(arr_sz, vector<int>(arr_sz));

        for (int i = 0; i < arr_sz; i ++) {
            int max_nb = arr[i];
            for (int j = i; j < arr_sz; j ++) {
                max_nb = max(max_nb, arr[j]);
                peak[i][j] = max_nb;
            }
        }

        for (int i = 0; i < arr_sz; i ++)
            dp[i][i] = 0;

        for (int len = 2; len <= arr_sz; len ++) {
            for (int i = 0; i + len - 1 < arr_sz; i ++) {
                int j = i + len - 1;
                for (int m = i; m < j; m ++) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j] + peak[i][m] * peak[m+1][j]);
                }
            }
        }

        return dp[0][arr_sz-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> arr;

    for (int i = 1; i < argc; i ++)
        arr.push_back(atoi(argv[i]));

    cout << solution.mctFromLeafValues(arr) << endl;

    return 0;
}
