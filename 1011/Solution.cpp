#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int ship(vector<int>& weights, int cap) {
        int days = 0;
        int load = 0;

        for (auto weight : weights) {
            if (load + weight > cap) {
                days ++;
                load = 0;
            }
            load += weight;
        }
        if (load)
            days ++;

        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = weights[0], h = 0;

        for (auto weight : weights) {
            l = max(l, weight);
            h += weight;
        }

        int ans = h;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (ship(weights, m) > D) {
                l = m + 1;
            } else {
                ans = m;
                h = m - 1;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int D = atoi(argv[1]);
    vector<int> weights;

    for (int i = 2; i < argc; i ++) {
        int n = atoi(argv[i]);
        weights.push_back(n);
    }

    cout << solution.shipWithinDays(weights, D) << endl;

    return 0;
}
