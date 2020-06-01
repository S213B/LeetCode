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
    void go(string &s, vector<vector<bool>> &is_palindrome, vector<vector<string>> &ans, vector<string> &an, int start) {
        if (start == s.size()) {
            ans.push_back(an);
            return;
        }

        for (int len = 1; start + len - 1 < s.size(); len ++) {
            int end = start + len - 1;
            if (is_palindrome[start][end]) {
                an.push_back(s.substr(start, len));
                go(s, is_palindrome, ans, an, end + 1);
                an.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> is_palindrome(s.size(), vector<bool>(s.size()));
        vector<vector<string>> ans;

        for (int len = 1; len <= s.size(); len ++) {
            for (int start = 0; start + len - 1 < s.size(); start ++) {
                int end = start + len - 1;
                if (len == 1) {
                    is_palindrome[start][end] = true;
                } else if (s[start] == s[end]) {
                    if (len == 2 || is_palindrome[start+1][end-1])
                        is_palindrome[start][end] = true;
                }
            }
        }

        vector<string> an;
        go(s, is_palindrome, ans, an, 0);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    vector<vector<string>> ans;

    ans = solution.partition(s);

    for (auto an : ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
