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
    int divide(int dividend, int divisor) {
        int ans = 0;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        unsigned a = dividend == INT_MIN ? INT_MAX+1 : abs(dividend);
        unsigned b = divisor == INT_MIN ? INT_MAX+1 : abs(divisor);
        for (int i = 31; i >= 0 && a >= b; i --) {
            if ((a >> i) >= b) {
                ans += 1 << i;
                a -= b << i;
            }
        }

        return ((dividend ^ divisor) >> 31) ? -ans : ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int dividend = atoi(argv[1]);
    int divisor = atoi(argv[2]);

    cout << solution.divide(dividend, divisor) << endl;

    return 0;
}
