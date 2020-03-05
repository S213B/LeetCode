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
    bool isMonotonic(vector<int>& A) {
#if 0
        const bool is_inc = (A.back() >= A[0]);

        for (int i = 1; i < A.size(); i ++) {
            if ((is_inc && A[i-1] > A[i]) ||
                (!is_inc && A[i-1] < A[i]))
                return false;
        }

        return true;
#else
#if 0
        bool is_inc = true, is_dec = true;

        for (int i = 1; i < A.size(); i ++) {
            is_inc &= A[i-1] <= A[i];
            is_dec &= A[i-1] >= A[i];
        }

        return is_inc || is_dec;
#else
        bool is_inc = false, is_dec = false;

        for (int i = 1; i < A.size(); i ++) {
            if (A[i-1] < A[i])
                is_inc = true;
            if (A[i-1] > A[i])
                is_dec = true;
            if (is_inc && is_dec)
                return false;
        }

        return true;
#endif
#endif
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> A;

    for (int i = 1; i < argc; i ++)
        A.push_back(atoi(argv[i]));

    cout << solution.isMonotonic(A) << endl;

    return 0;
}
