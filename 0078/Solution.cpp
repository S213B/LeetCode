#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        uint32_t id_max = 1 << (nums.size());
        vector<vector<int>> ans(id_max, vector<int>());

#if 0
        for (int id = 0; id < id_max; id ++) {
            vector<int> subset;
            for (int i = 0; i < nums.size(); i ++) {
                if (id & (1 << i))
                    subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }
#else
        for (int i = 0; i < nums.size(); i ++) {
            int step = 1 << i;
            for (int start = step; start < id_max; start += step * 2) {
                for (int j = start; j < start + step; j ++) {
                    ans[j].push_back(nums[i]);
                }
            }
        }
#endif

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    vector<vector<int>> ans;

    for (int i = 1; i < argc; i ++) {
        int n = atoi(argv[i]);
        nums.push_back(n);
    }

    ans = solution.subsets(nums);

    for (auto &an: ans) {
        for (auto n : an)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
