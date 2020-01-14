#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

class Solution {
private:
    int to_num(int x, int y) {
        if (x == 1 && y == -1)
            return 0;
        if (x < 0 || y < 0 || x >= 3 || y >= 3)
            return -1;
        return 1 + (y * 3 + x);
    }
    void to_loc(int num, int &x, int &y) {
        if (!num) {
            x = 1;
            y = -1;
        } else {
            num --;
            y = num / 3;
            x = num - (y * 3);
        }
    }

public:
    int knightDialer(int N) {
        int ans = 0, mod = 1000000007;
        int num[10] = {1,1,1,1,1,1,1,1,1,1};
        int move[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

        if (!N)
            return 0;

        while (--N) {
            int new_num[10] = {0};
            for (int i = 0; i < 10; i ++) {
                int x, y;
                to_loc(i, x, y);
                for (int j = 0; j < 8; j ++) {
                    int xx = x + move[j][0];
                    int yy = y + move[j][1];
                    int ii = to_num(xx, yy);
                    if (ii < 0)
                        continue;
                    new_num[ii] += num[i];
                    new_num[ii] %= mod;
                }
            }
            memcpy(num, new_num, sizeof(num));
        }

        for (int i = 0; i < 10; i ++) {
            ans += num[i];
            ans %= mod;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int N = atoi(argv[1]);

    cout << solution.knightDialer(N) << endl;

    return 0;
}
