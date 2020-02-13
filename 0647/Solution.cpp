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
    int countSubstrings(string s) {
        vector<vector<bool>> is_pal(s.size(), vector<bool>(s.size()));
        int ans = 0;

        for (int len = 1; len <= s.size(); len ++) {
            for (int i = 0; i+len-1 < s.size(); i ++) {
                int j = i + len - 1;
                if (len == 1 || ((len == 2 || is_pal[i+1][j-1]) && s[i] == s[j])) {
                    is_pal[i][j] = true;
                    ans ++;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.countSubstrings(s) << endl;

    return 0;
}
