#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        uint32_t id_max = 1 << (nums.size());

        for (int id = 0; id < id_max; id ++) {
            vector<int> subset;
            for (int i = 0; i < nums.size(); i ++) {
                if (id & (1 << i))
                    subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }

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
