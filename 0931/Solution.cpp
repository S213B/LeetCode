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
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<int> path = A[0], new_path;
        int ans;

        for (int i = 1; i < A.size(); i ++) {
            vector<int> &row = A[i];
            new_path.clear();
            for (int j = 0; j < row.size(); j ++) {
                int t = path[j];
                if (j)
                    t = min(t, path[j-1]);
                if (j < path.size() - 1)
                    t = min(t, path[j+1]);
                new_path.push_back(row[j] + t);
            }
            path = new_path;
        }

        ans = path[0];
        for (int i = 1; i < path.size(); i ++) {
            ans = min(path[i], ans);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> A;
    vector<int> row;
    int row_sz = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() >= row_sz) {
            A.push_back(row);
            row.clear();
        }
    }

    cout << solution.minFallingPathSum(A) << endl;

    return 0;
}
