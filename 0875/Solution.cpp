#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int eat_all(vector<int> &piles, int K) {
        int h = 0;
        for (auto p : piles)
            h += (p + K - 1) / K;
        return h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, h = -1;

        for (auto p : piles)
            h = max(h, p);

        while (l <= h) {
            int m = l + (h - l) / 2;
            int t = eat_all(piles, m);
            if (t > H) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int H = atoi(argv[1]);
    vector<int> piles;

    for (int i = 2; i < argc; i ++)
        piles.push_back(atoi(argv[i]));

    cout << solution.minEatingSpeed(piles, H) << endl;

    return 0;
}
