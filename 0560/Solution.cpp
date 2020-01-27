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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int ans = 0;

        map[0] = 1;
        for (int i = 0, sum = 0; i < nums.size(); i ++) {
            sum += nums[i];
            if (map.count(sum - k))
                ans += map[sum - k];
            map[sum] ++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int k = atoi(argv[1]), n;
    vector<int> nums;

    while (cin >> n)
        nums.push_back(n);

    cout << solution.subarraySum(nums, k) << endl;

    return 0;
}
