#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        int dp[nb+1];
        int prev;

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < na+1; i ++) {
            int prev = 0;
            for (int j = 1; j < nb+1; j ++) {
                int t = dp[j];
                if (A[i-1] == B[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = t;
            }
        }

        return dp[nb];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;
    vector<int> B;
    int A_sz = atoi(argv[1]);
    int B_sz = atoi(argv[2]);
    int n;

    for (int i = 0; i < A_sz; i ++) {
        cin >> n;
        A.push_back(n);
    }

    for (int i = 0; i < B_sz; i ++) {
        cin >> n;
        B.push_back(n);
    }

    cout << solution.maxUncrossedLines(A, B) << endl;

    return 0;
}
