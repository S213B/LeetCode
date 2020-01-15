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
private:
    bool helper(int N, bool is_Alice, unordered_map<int, bool> &memo) {
        if (memo.count(N))
            return memo[N];
        bool done = true;
        bool Alice_win = is_Alice ? false : true;
        for (int i = 1; i < N; i ++) {
            if (N % i == 0) {
                done = false;
                if (is_Alice && helper(N-i, !is_Alice, memo)) {
                    Alice_win = true;
                    break;
                } else if (!is_Alice && !helper(N-i, !is_Alice, memo)) {
                    Alice_win = false;
                    break;
                }
            }
        }
        if (done) {
            memo[N] = !is_Alice;
            return !is_Alice;
        }
        memo[N] = Alice_win;
        return Alice_win;
    }

public:
    bool divisorGame(int N) {
        unordered_map<int, bool> memo;
        return helper(N, true, memo);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int N = atoi(argv[1]);

    cout << solution.divisorGame(N) << endl;

    return 0;
}
