#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp;

        if (!word1.size() || !word2.size())
            return word1.size() + word2.size();

        for (int i = 0; i < word1.size(); i++) {
            vector<int> v(word2.size(), 0);
            dp.push_back(v);
        }

        dp[0][0] = (word1[0] == word2[0] ? 0 : 1);
        for (int i = 1; i < word1.size(); i++)
            dp[i][0] = (word1[i] == word2[0] ? i : dp[i-1][0]+1);
        for (int i = 1; i < word2.size(); i++)
            dp[0][i] = (word1[0] == word2[i] ? i : dp[0][i-1]+1);

        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int insert = dp[i][j-1] + 1;
                    int remove = dp[i-1][j] + 1;
                    int replace = dp[i-1][j-1] + 1;
                    dp[i][j] = min(insert, min(remove, replace));
                }
            }
        }

#if 0
        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                cout << dp[i][j];
            }
            cout << endl;
        }
#endif

        return dp[word1.size()-1][word2.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string word1(argv[1]);
    string word2(argv[2]);

    cout << solution.minDistance(word1, word2) << endl;

    return 0;
}
