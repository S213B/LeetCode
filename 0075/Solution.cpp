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
    void sortColors(vector<int>& nums) {
        for (int i = 0, c1_cnt = 0, c12_cnt = 0; i < nums.size(); i ++) {
            int n = nums[i];
            nums[i] = 2;
            if (n == 1) {
                nums[c12_cnt ++] = 1;
            } else if (!n) {
                if (c12_cnt > c1_cnt)
                    nums[c12_cnt] = 1;
                c12_cnt ++;
                nums[c1_cnt ++] = 0;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    solution.sortColors(nums);

    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
