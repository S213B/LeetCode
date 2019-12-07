#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int _totalNQueens(vector<bool> &col, vector<bool> &diag, vector<bool> &diag2, int cur, int max) {
        if (cur == max)
            return 1;

        int ans = 0;
        
        for (int i = 0; i < max; i++) {
            int diag_idx = max + cur - i - 1;
            int diag2_idx = i + cur;
            if (!col[i] && !diag[diag_idx] && !diag2[diag2_idx]) {
                col[i] = diag[diag_idx] = diag2[diag2_idx] = true;
                ans += _totalNQueens(col, diag, diag2, cur+1, max);
                col[i] = diag[diag_idx] = diag2[diag2_idx] = false;
            }
        }

        return ans;
    }

public:
    int totalNQueens(int n) {
        if (n < 2)
            return 1;
        vector<bool> col(n, false);
        vector<bool> diag(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        return _totalNQueens(col, diag, diag2, 0, n);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);

    n = solution.totalNQueens(n);
    cout << n << endl;

    return 0;
}
