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
    int minCostClimbingStairs(vector<int>& cost) {
        int one = 0, two = 0, cur = 0;

        for (int i = 2; i < cost.size()+1; i ++) {
            cur = min(two + cost[i-2], one + cost[i-1]);
            two = one;
            one = cur;
        }

        return cur;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> cost;

    for (int i = 1; i < argc; i ++) {
        cost.push_back(atoi(argv[i]));
    }

    cout << solution.minCostClimbingStairs(cost) << endl;

    return 0;
}
