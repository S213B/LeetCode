#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size(), 0);
        int last;

        if (!word1.size() || !word2.size())
            return word1.size() + word2.size();

        dp[0] = (word1[0] == word2[0] ? 0 : 1);
        for (int i = 1; i < word2.size(); i++)
            dp[i] = (word1[0] == word2[i] ? i : dp[i-1]+1);

        for (int i = 1; i < word1.size(); i++) {
            last = dp[0];
            dp[0] = (word1[i] == word2[0]) ? i : last+1;
            for (int j = 1; j < word2.size(); j++) {
                int tmp_last = dp[j];
                if (word1[i] == word2[j]) {
                    dp[j] = last;
                } else {
                    int insert = dp[j-1] + 1;
                    int remove = dp[j] + 1;
                    int replace = last + 1;
                    dp[j] = min(insert, min(remove, replace));
                }
                last = tmp_last;
            }
        }

        return dp[word2.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string word1(argv[1]);
    string word2(argv[2]);

    cout << solution.minDistance(word1, word2) << endl;

    return 0;
}
