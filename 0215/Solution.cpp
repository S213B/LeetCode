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
private:
    void _swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    int _findKthLargest(vector<int> &nums, int s, int e, int k) {
        while (1) {
            int kk = s;
            int ee = e;
            int i = s + 1;

            while (i <= ee) {
                if (nums[i] < nums[kk]) {
                    _swap(nums[i], nums[kk]);
                    kk ++;
                    i ++;
                } else if (nums[i] == nums[kk]) {
                    i ++;
                } else {
                    _swap(nums[i], nums[ee]);
                    ee --;
                }
            }

            if (kk == k)
                return nums[kk];
            else if (kk < k)
                s = kk + 1;
            else
                e = kk - 1;
        }

        return -1;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return _findKthLargest(nums, 0, nums.size()-1, nums.size()-k);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    int k = atoi(argv[1]);
    int n;

    while (cin >> n) {
        nums.push_back(n);
    }

    cout << solution.findKthLargest(nums, k) << endl;

    return 0;
}
