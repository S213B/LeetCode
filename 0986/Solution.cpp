#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            vector<int> &a = A[i];
            vector<int> &b = B[j];
            if (a[0] < b[0]) {
                if (a[1] < b[0]) {
                    i ++;
                } else if (a[1] <= b[1]) {
                    ans.push_back({b[0], a[1]});
                    i ++;
                    if (a[1] == b[1])
                        j ++;
                    else
                        b[0] = a[1] + 1;
                } else {
                    ans.push_back({b[0], b[1]});
                    a[0] = b[1] + 1;
                    j ++;
                }
            } else if (a[0] <= b[1]) {
                if (a[1] <= b[1]) {
                    ans.push_back({a[0], a[1]});
                    i ++;
                    if (a[1] == b[1])
                        j ++;
                    else
                        b[0] = a[1] + 1;
                } else {
                    ans.push_back({a[0], b[1]});
                    a[0] = b[1] + 1;
                    j ++;
                }
            } else {
                j ++;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> A = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> B = {{1,5}, {8,12}, {15,24}, {25,26}};
    vector<vector<int>> ans;

    ans = solution.intervalIntersection(A, B);

    for (auto a : ans) {
        cout << a[0] << "," << a[1] << " ";
    }
    cout << endl;

    return 0;
}
