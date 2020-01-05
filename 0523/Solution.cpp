#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * [1,2], 0 => false
 * [0,0], 0 => true
 * [0,0], 1 => true
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> r2i;
        int sum = 0, r;

        r2i[0] = -1;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            r = k ? (sum % k) : sum;
            if (!r2i.count(r))
                r2i[r] = i;
            else if (i - r2i[r] > 1)
                return true;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int k = atoi(argv[1]);
    vector<int> nums;

    for (int i = 2; i < argc; i ++) {
        int n = atoi(argv[i]);
        nums.push_back(n);
    }

    cout << solution.checkSubarraySum(nums, k) << endl;

    return 0;
}
