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
    void nextPermutation(vector<int>& nums) {
        int ii, jj = -1;

        for (int i = nums.size()-1; i >= 0; i --) {
            for (int j = i-1; j >= 0; j --) {
                if (nums[j] >= nums[i])
                    continue;
                if (j > jj || (j == jj && nums[i] < nums[ii])) {
                    ii = i;
                    jj = j;
                }
            }
        }

        if (jj >= 0) {
            int t = nums[ii];
            nums[ii] = nums[jj];
            nums[jj] = t;
            sort(nums.begin()+jj+1, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }

        return;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    solution.nextPermutation(nums);

    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
