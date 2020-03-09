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
    string minRemoveToMakeValid(string s) {
        int cnt = 0;

        for (auto &c : s) {
            if (c == '(') {
                cnt ++;
            } else if (c == ')') {
                if (cnt == 0) {
                    c = '*';
                } else {
                    cnt --;
                }
            }
        }

        for (int i = s.size()-1; cnt && i >= 0; i --) {
            if (s[i] == '(') {
                s[i] = '*';
                cnt --;
            }
        }

        int len = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != '*')
                s[len++] = s[i];
        }
        s.resize(len);

        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.minRemoveToMakeValid(s) << endl;

    return 0;
}
