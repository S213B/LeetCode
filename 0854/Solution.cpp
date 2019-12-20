#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int kSimilarity(string A, string B) {
        vector<vector<int>> map(256, vector<int>(256, 0));
        int map_sz = 0;
        int ans;

        for (int i = 0; i < A.size(); i ++) {
            if (A[i] == B[i])
                continue;
            if (map[A[i]][B[i]]) {
                map[A[i]][B[i]] --;
                map_sz --;
                ans ++;
            } else {
                map[B[i]][A[i]] ++;
                map_sz ++;
            }
        }

        if (map_sz)
            ans += map_sz - 1;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string A(argv[1]);
    string B(argv[2]);

    cout << solution.kSimilarity(A, B) << endl;

    return 0;
}
