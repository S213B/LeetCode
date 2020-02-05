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

#if 0
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
#else
class Solution {
private:
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

public:
    void sortColors(vector<int>& nums) {
        int c1 = 0, c2 = 0, c3 = nums.size() - 1;

        while (c2 <= c3) {
            int n = nums[c2];
            if (!n) {
                swap(nums, c1, c2);
                c1 ++;
                c2 ++;
            } else if (n == 1) {
                c2 ++;
            } else if (n == 2) {
                swap(nums, c2, c3);
                c3 --;
            }
        }
    }
};
#endif

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
