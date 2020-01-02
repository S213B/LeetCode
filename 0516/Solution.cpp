#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> match(s.size(), vector<int>(s.size(), 0));
        int n = s.size();

        if (n < 2)
            return s.size();

        for (int i = 0; i < n; i ++)
            match[i][i] = 1;

        for (int len = 2; len <= n; len ++) {
            for (int i = 0; i + len - 1 < n; i ++) {
                int end = i + len - 1;
                if (s[i] == s[end]) {
                    match[i][end] = match[i+1][end-1] + 2;
                } else {
                    match[i][end] = max(match[i][end-1], match[i+1][end]);
                }
            }
        }

        return match[0][n-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.longestPalindromeSubseq(s) << endl;

    return 0;
}
