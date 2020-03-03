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
    int sumSubseqWidths(vector<int>& A) {
        long mod = 1e9 + 7, ans = 0, p2 = 1;
        long n = A.size();

        sort(A.begin(), A.end());

        for (int i = 0; i < n; i ++, p2 = (p2 * 2) % mod) {
            ans = (ans + A[i] * p2 - A[n-1-i] * p2) % mod;
        }

        return (ans + mod) % mod;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;

    for (int i = 1; i < argc; i ++)
        A.push_back(atoi(argv[i]));

    cout << solution.sumSubseqWidths(A) << endl;

    return 0;
}
