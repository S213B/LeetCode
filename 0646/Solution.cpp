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
    static bool my_cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), my_cmp);

        if (!pairs.size())
            return 0;

        int ans = 1, p1 = pairs[0][1];

        for (int i = 1; i < pairs.size(); i ++) {
            if (pairs[i][0] > p1) {
                p1 = pairs[i][1];
                ans ++;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> pairs;
    int n1, n2;

    while (cin >> n1 && cin >> n2) {
        vector<int> pair{n1, n2};
        pairs.push_back(pair);
    }

    cout << solution.findLongestChain(pairs) << endl;

    return 0;
}
