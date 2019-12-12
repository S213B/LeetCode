#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& A, int i, int j) {
        if (!A[i][j])
            return;
        A[i][j] = 0;
        if (i)
            dfs(A, i-1, j);
        if (j)
            dfs(A, i, j-1);
        if (i < A.size()-1)
            dfs(A, i+1, j);
        if (j < A[i].size()-1)
            dfs(A, i, j+1);
    }

public:
    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;

        for (int i = 0; i < A.size(); i ++) {
            if (A[i][0])
                dfs(A, i, 0);
            if (A[i][A[i].size()-1])
                dfs(A, i, A[i].size()-1);
        }
        for (int j = 0; j < A[0].size(); j ++) {
            if (A[0][j])
                dfs(A, 0, j);
            if (A[A.size()-1][j])
                dfs(A, A.size()-1, j);
        }

        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < A[i].size(); j ++) {
                ans += A[i][j];
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;
    vector<int> row;
    int n = atoi(argv[1]);
    int nn;

    while (cin >> nn) {
        row.push_back(nn);
        if (row.size() == n) {
            grid.push_back(row);
            row.clear();
        }
    }

    for (auto &r : grid) {
        for (auto nnn : r) {
            cout << nnn << " ";
        }
        cout << endl;
    }

    cout << solution.numEnclaves(grid) << endl;

    return 0;
}
