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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end()), ans;

        for (auto n : nums2) {
            if (set.count(n))
                ans.insert(n);
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums1, nums2, ans;
    int n;

    for (int i = 1; i < argc; i ++)
        nums1.push_back(atoi(argv[i]));

    while (cin >> n)
        nums2.push_back(n);

    ans = solution.intersection(nums1, nums2);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;
    
    return 0;
}
