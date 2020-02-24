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
        stack<int> stk;

        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < nums.size(); j ++) {
                int n = nums[j];
                while (stk.size() && nums[stk.top()] < n) {
                    int k = stk.top();
                    stk.pop();
                    ans[k] = n;
                }
                stk.push(j);
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
