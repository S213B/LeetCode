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

/*
 * Symbol       Value
 *   I            1
 *   V            5
 *   X            10
 *   L            50
 *   C            100
 *   D            500
 *   M            1000
 *
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 */
class Solution {
public:
    int romanToInt(string s) {
        int ch_to_idx[128] = {0};
        int idx_to_int[] = {1, 5, 10, 50, 100, 500, 1000};
        int ans = 0, val = 0;

        ch_to_idx['I'] = 0;
        ch_to_idx['V'] = 1;
        ch_to_idx['X'] = 2;
        ch_to_idx['L'] = 3;
        ch_to_idx['C'] = 4;
        ch_to_idx['D'] = 5;
        ch_to_idx['M'] = 6;

        for (int i = 0, last_idx = INT_MAX; i < s.size(); i ++) {
            char idx = ch_to_idx[s[i]];
            if (idx != last_idx) {
                if (idx > last_idx)
                    val *= -1;
                ans += val;
                last_idx = idx;
                val = 0;
            }
            val += idx_to_int[idx];
        }
        ans += val;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.romanToInt(s) << endl;

    return 0;
}
