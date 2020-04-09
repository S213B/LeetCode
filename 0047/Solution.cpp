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
    struct node {
        int val;
        int cnt;
        node(int v, int c) : val(v), cnt(c) {}
    };

    void recursion(vector<vector<int>> &ans, vector<struct node> &nodes, vector<int> &an, int cur) {
        if (cur == an.size()) {
            ans.push_back(an);
            return;
        }

        for (int i = 0; i < nodes.size(); i ++) {
            if (!nodes[i].cnt)
                continue;
            an[cur] = nodes[i].val;
            nodes[i].cnt --;
            recursion(ans, nodes, an, cur+1);
            nodes[i].cnt ++;
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> an(nums.size());
        vector<struct node> nodes;

        sort(nums.begin(), nums.end());

        for (int i = 0, cnt = 1; i < nums.size(); i ++) {
            if (i == nums.size()-1 || nums[i] != nums[i+1]) {
                nodes.push_back({nums[i], cnt});
                cnt = 1;
            } else {
                cnt ++;
            }
        }

        recursion(ans, nodes, an, 0);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    ans = solution.permuteUnique(nums);

    for (auto &an : ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
