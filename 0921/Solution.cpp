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
    int minAddToMakeValid(string S) {
        int open_left = 0, open_added = 0;

        for (auto c : S) {
            if (c == '(') {
                open_left ++;
            } else {
                open_left --;
                if (open_left < 0) {
                    open_added ++;
                    open_left = 0;
                }
            }
        }

        return open_left + open_added;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);

    cout << solution.minAddToMakeValid(S) << endl;

    return 0;
}
