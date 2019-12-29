#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));

        for (int i = 1; i <= A.size(); i ++) {
            for (int j = 1; j <= B.size(); j ++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[A.size()][B.size()];
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
