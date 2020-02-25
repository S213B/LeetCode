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
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0;
        int mod = 1000000007;
        stack<pair<int, int>> stk;
        vector<pair<int, int>> vvv(A.size());

        A.push_back(INT_MIN);
        for (int i = 0; i < A.size(); i ++) {
            int len = 1;
            while (stk.size() && A[stk.top().first] >= A[i]) {
                len += stk.top().second;
                vvv[stk.top().first].first = stk.top().second;
                vvv[stk.top().first].second = i - stk.top().first;
                stk.pop();
            }
            stk.push(make_pair(i, len));
        }

        for (int i = 0; i < vvv.size(); i ++) {
            int l = vvv[i].first;
            int r = vvv[i].second;
            ans += l * r * A[i];
            ans %= mod;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;

    for (int i = 0; i < argc; i ++)
        A.push_back(atoi(argv[i]));

    cout << solution.sumSubarrayMins(A) << endl;

    return 0;
}
