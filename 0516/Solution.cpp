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

        if (s.size() < 2)
            return s.size();

        for (int i = 0; i < s.size(); i ++)
            match[i][i] = 1;

        for (int len = 2; len <= s.size(); len ++) {
            for (int i = 0; i + len - 1 < s.size(); i ++) {
                int t = max(match[i][i+len-2], match[i+1][i+len-1]);
                match[i][i+len-1] = match[i+1][i+len-2] + (s[i] == s[i+len-1] ? 2 : 0);
                match[i][i+len-1] = max(match[i][i+len-1], t);
            }
        }

        return match[0][s.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.longestPalindromeSubseq(s) << endl;

    return 0;
}
