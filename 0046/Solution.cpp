#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    vector<vector<int>> ans;

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        nums.push_back(num);
    }

    ans = solution.permute(nums);

    for (auto &perm : ans) {
        for (auto p : perm)
            cout << p << " ";
        cout << endl;
    }

    return 0;
}
