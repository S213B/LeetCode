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
    void recursion(vector<int>& nums, vector<int>& cnt, vector<vector<int>> &ans, vector<int> &an, int cur, int left) {
        if (!left) {
            ans.push_back(an);
            return;
        }

        for (int i = cur; i < nums.size(); i += cnt[i]) {
            an.push_back(nums[i]);
            recursion(nums, cnt, ans, an, i+1, left-1);
            an.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> an;
        vector<int> cnt(nums.size(), 1);

        sort(nums.begin(), nums.end());

        for (int i = cnt.size()-2; i >= 0; i --) {
            if (nums[i] == nums[i+1])
                cnt[i] += cnt[i+1];
        }

        for (int left = 0; left <= nums.size(); left ++)
            recursion(nums, cnt, ans, an, 0, left);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    ans = solution.subsetsWithDup(nums);

    for (auto an : ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
