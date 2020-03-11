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
    bool checkInclusion(string s1, string s2) {
        char tgt[256] = {0};
        char cur[256] = {0};
        int diff = 0, l1 = s1.size();

        for (auto c : s1) {
            if (!tgt[c])
                diff ++;
            tgt[c] ++;
        }

        for (int i = 0; i < s2.size(); i ++) {
            int tail = i - l1;
            if (tail >= 0) {
                char c = s2[tail];
                cur[c] --;
                if (cur[c] == tgt[c])
                    diff --;
                else if (cur[c] + 1 == tgt[c])
                    diff ++;
            }
            char c = s2[i];
            cur[c] ++;
            if (cur[c] == tgt[c])
                diff --;
            else if (cur[c] - 1 == tgt[c])
                diff ++;
            if (!diff)
                return true;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.checkInclusion(s1, s2) << endl;

    return 0;
}
