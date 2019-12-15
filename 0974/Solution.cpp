#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> r_cnt(K, 0);
        int ans = 0, r = 0;

        r_cnt[0] = 1;
        for (int i = 0; i < A.size(); i ++) {
            r += A[i];
            r %= K;
            if (r < 0)
                r += K;
            ans += r_cnt[r];
            r_cnt[r] ++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;
    int K = atoi(argv[argc-1]);

    for (int i = 1; i < argc - 1; i ++) {
        int n = atoi(argv[i]);
        A.push_back(n);
    }

    cout << solution.subarraysDivByK(A, K) << endl;

    return 0;
}
