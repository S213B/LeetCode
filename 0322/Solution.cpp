#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> cnt(amount+1, amount+1);

        cnt[0] = 0;

        for (int i = 0; i < cnt.size(); i ++) {
            for (auto c : coins) {
                if (i < c)
                    continue;
                cnt[i] = min(cnt[i], cnt[i-c] + 1);
            }
        }

        return (cnt[amount] == amount + 1) ? -1 : cnt[amount];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> coins;
    int amount = atoi(argv[argc-1]);

    for (int i = 1; i < argc - 1; i++) {
        int coin = atoi(argv[i]);
        coins.push_back(coin);
    }

    cout << solution.coinChange(coins, amount) << endl;

    return 0;
}
