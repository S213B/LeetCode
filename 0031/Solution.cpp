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
        int i = nums.size()-2;

        while (i >= 0) {
            if (nums[i] < nums[i+1])
                break;
            i --;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = nums.size()-1;
            while (nums[j] <= nums[i])
                j --;
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
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
