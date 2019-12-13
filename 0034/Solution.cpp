#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int l, h;

        l = 0;
        h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (l < nums.size() && nums[l] == target)
            ans[0] = l;

        l = 0;
        h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        if (h >= 0 && nums[h] == target)
            ans[1] = h;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums, ans;
    int target = atoi(argv[1]);

    for (int i = 2; i < argc; i ++) {
        int num = atoi(argv[i]);
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    ans = solution.searchRange(nums, target);

    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}
