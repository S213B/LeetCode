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
    static bool my_cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second >= b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<vector<int>> freq(nums.size());
        vector<pair<int, int>> nb2cnt;
        unordered_map<int, int> nb2idx;

        for (auto n : nums) {
            if (nb2idx.count(n)) {
                nb2cnt[nb2idx[n]].second ++;
            } else {
                nb2idx[n] = nb2cnt.size();
                nb2cnt.push_back(make_pair(n, 1));
            }
        }

#if 0
        nth_element(nb2cnt.begin(), nb2cnt.begin() + k - 1, nb2cnt.end(), my_cmp);

        for (int i = 0; i < k; i ++) {
            ans.push_back(nb2cnt[i].first);
        }
#else
        for (auto &p : nb2cnt)
            freq[p.second - 1].push_back(p.first);
        
        for (int i = freq.size()-1; i >= 0; i --) {
            for (int j = 0; j < freq[i].size() && ans.size() < k; j ++) {
                ans.push_back(freq[i][j]);
            }
        }
#endif

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    int k = atoi(argv[1]);
    int n;

    while (cin >> n) {
        nums.push_back(n);
    }

    nums = solution.topKFrequent(nums, k);

    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
