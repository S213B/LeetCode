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
    int minimumSwap(string s1, string s2) {
        int diff_cnt = 0, xy = 0;

        for (int i = 0; i < s1.size(); i ++) {
            if (s1[i] != s2[i]) {
                diff_cnt ++;
                if (s1[i] == 'x')
                    xy ++;
            }
        }

        if (diff_cnt & 1)
            return -1;

        diff_cnt /= 2;

        return (xy & 1) ? diff_cnt + 1 : diff_cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.minimumSwap(s1, s2) << endl;

    return 0;
}
