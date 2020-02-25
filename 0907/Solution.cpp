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
        stack<int> stk;

        A.push_back(INT_MIN);
        for (int i = 0; i < A.size(); i ++) {
            while (stk.size() && A[stk.top()] >= A[i]) {
                int j = stk.top();
                stk.pop();
                int l = j - (stk.size() ? stk.top() : -1);
                int r = i - j;
                ans += l * r * A[j];
                ans %= mod;
            }
            stk.push(i);
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
