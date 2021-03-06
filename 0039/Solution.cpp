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
    void _combinationSum(vector<int> &candidates, int i, int target, vector<int> &an, vector<vector<int>> &ans) {
        if (!target) {
            ans.push_back(an);
            return;
        }

        while (i < candidates.size()) {
            int c = candidates[i];
            if (c > target)
                break;
            an.push_back(c);
            _combinationSum(candidates, i, target - c, an, ans);
            an.pop_back();
            i ++;
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> an;

        sort(candidates.begin(), candidates.end());

        _combinationSum(candidates, 0, target, an, ans);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> ans;
    vector<int> candidates;
    int target = atoi(argv[1]);
    int n;

    while (cin >> n)
        candidates.push_back(n);

    ans = solution.combinationSum(candidates, target);

    for (auto &an : ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
