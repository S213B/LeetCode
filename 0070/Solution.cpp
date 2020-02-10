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
    int climbStairs(int n) {
        int one_away = 1, two_away = 1;

        for (int i = 2; i <= n; i ++) {
            int cur = one_away + two_away;
            two_away = one_away;
            one_away = cur;
        }

        return one_away;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);

    cout << solution.climbStairs(n) << endl;

    return 0;
}
