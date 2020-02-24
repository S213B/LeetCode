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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> map;
        stack<int> stk;

        for (auto n : nums2) {
            while (stk.size() && stk.top() < n) {
                int sn = stk.top();
                stk.pop();
                map[sn] = n;
            }
            stk.push(n);
        }

        for (int i = 0; i < nums1.size(); i ++) {
            int n = nums1[i];
            if (map.count(n))
                ans[i] = map[n];
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2, ans;
    int n;

    for (int i = 1; i < argc; i ++) {
        n = atoi(argv[i]);
        nums2.push_back(n);
    }

    while (cin >> n)
        nums1.push_back(n);

    ans = solution.nextGreaterElement(nums1, nums2);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
