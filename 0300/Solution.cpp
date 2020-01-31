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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for (auto n : nums) {
            int l = 0, h = dp.size()-1;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if (dp[m] >= n) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (h == dp.size()-1)
                dp.push_back(n);
            else
                dp[h+1] = n;
        }

        return dp.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}
