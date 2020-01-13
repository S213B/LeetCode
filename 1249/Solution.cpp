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
        string _ans, ans;
        int open = 0;

        for (auto &c : s) {
            if (c == '(') {
                open ++;
            } else if (c == ')') {
                open --;
                if (open < 0) {
                    c = '*';
                    open ++;
                }
            }
        }

        for (int i = s.size()-1; open && i >= 0; i --) {
            if (s[i] == '(') {
                s[i] = '*';
                open --;
            }
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.minRemoveToMakeValid(s) << endl;

    return 0;
}
