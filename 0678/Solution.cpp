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
    bool checkValidString(string s) {
        int lower = 0, higher = 0;

        for (auto c : s) {
            if (c == '(') {
                lower ++;
                higher ++;
            } else if (c == ')') {
                if (!higher)
                    return false;
                lower = max(0, lower - 1);
                higher --;
            } else {
                lower = max(0, lower - 1);
                higher ++;
            }
        }

        return lower == 0;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.checkValidString(s) << endl;

    return 0;
}
