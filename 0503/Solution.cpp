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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        vector<int> stack;

        for (int loop = 0; loop < 2; loop ++) {
            for (int i = 0; i < nums.size(); i ++) {
                int n = nums[i];
                while (stack.size() && nums[stack.back()] < n) {
                    int idx = stack.back();
                    stack.pop_back();
                    ans[idx] = nums[i];
                }
                stack.push_back(i);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++) {
        int n = atoi(argv[i]);
        nums.push_back(n);
    }

    nums = solution.nextGreaterElements(nums);

    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
