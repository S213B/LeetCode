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
    void vv_append(vector<vector<int>> &vv, int x) {
        for (auto &v : vv)
            v.push_back(x);
    }

public:
    int uniqueLetterString(string s) {
        vector<vector<int>> vv(26);
        int ans = 0, mod = 1e9+7, n = s.size();

        vv_append(vv, -1);
        for (int i = 0; i < n; i ++) {
            int idx = s[i] - 'A';
            vv[idx].push_back(i);
        }
        vv_append(vv, n);

        for (auto &v : vv) {
            for (int i = 1; i < v.size()-1; i ++) {
                int l = v[i] - v[i-1];
                int r = v[i+1] - v[i];
                ans += (l * r) % mod;
                ans %= mod;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.uniqueLetterString(s) << endl;

    return 0;
}
