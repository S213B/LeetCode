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
    int helper(string &s, char ch_open) {
        int open = 0, n = s.size();
        queue<int> star;

        for (int i = 0; i < n; i ++) {
            int c = s[i];
            if (c == '*') {
                star.push(i);
            } else if (c == ch_open) {
                open ++;
            } else {
                open --;
                if (open < 0) {
                    if (!star.size())
                        return -1;
                    s[star.front()] = ch_open;
                    star.pop();
                    open ++;
                }
            }
        }

        return open;
    }

public:
    bool checkValidString(string s) {
        int open_left;

        open_left = helper(s, '(');
        if (open_left <= 0)
            return !open_left;

        reverse(s.begin(), s.end());

        open_left = helper(s, ')');
        return open_left >= 0;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.checkValidString(s) << endl;

    return 0;
}
