#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
private:
    static bool my_cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return (a[1] > b[1]);
        return (a[0] < b[0]);
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> dp;

        sort(envelopes.begin(), envelopes.end(), my_cmp);

        for (auto &e : envelopes) {
            int v = e[1];
            int l = 0, h = dp.size()-1;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if (dp[m] >= v) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (h == dp.size()-1)
                dp.push_back(v);
            else
                dp[h+1] = v;
        }

        return dp.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> envelopes;
    int n1, n2;

    while ((cin >> n1) && (cin >> n2)) {
        vector<int> row{n1, n2};
        envelopes.push_back(row);
    }

    cout << solution.maxEnvelopes(envelopes) << endl;

    return 0;
}
