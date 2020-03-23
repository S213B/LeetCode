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
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            int n = nums[m];
            if (n == target)
                return m;
            if (n < target) {
                if (nums[l] <= n) {
                    l = m + 1;
                } else if (target >= nums[l]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (n <= nums[h]) {
                    h = m - 1;
                } else if (target >= nums[l]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int target = atoi(argv[1]), n;
    vector<int> nums;

    while (cin >> n)
        nums.push_back(n);

    cout << solution.search(nums, target) << endl;
    
    return 0;
}
