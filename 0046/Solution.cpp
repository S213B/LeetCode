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
    void my_swap(vector<int> &v, int i, int j) {
        int t = v[i];
        v[i] = v[j];
        v[j] = t;
    }

    void recursion(vector<vector<int>> &ans, vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = cur; i < nums.size(); i ++) {
            my_swap(nums, cur, i);
            recursion(ans, nums, cur+1);
            my_swap(nums, cur, i);
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
#if 0
        vector<vector<int>> ans;

        ans.push_back(nums);

        for (int i = 0; i < nums.size(); i++) {
            int ans_sz = ans.size();
            for (int j = 0; j < ans_sz; j++) {
                for (int k = i+1; k < nums.size(); k++) {
                    vector<int> new_n(ans[j].begin(), ans[j].end());
                    int t = new_n[k];
                    new_n[k] = new_n[i];
                    new_n[i] = t;
                    ans.push_back(new_n);
                }
            }
        }

        return ans;
#else
        vector<vector<int>> ans;

        recursion(ans, nums, 0);

        return ans;
#endif
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;
    vector<int> nums;

    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));

    ans = solution.permute(nums);

    for (auto &an: ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
