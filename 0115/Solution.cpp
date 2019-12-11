#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long> dp(t.size(), 0);

        for (int i = 0; i < s.size(); i ++) {
            for (int j = t.size()-1; j >= 0; j --) {
                if (s[i] == t[j])
                    dp[j] += j ? dp[j-1] : 1;
            }
        }

        return dp.back();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    string t(argv[2]);

    cout << solution.numDistinct(s, t) << endl;

    return 0;
}
