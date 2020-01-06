#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = 0; i < s.size() && ans < g.size(); i ++) {
            if (s[i] < g[ans])
                continue;
            ans ++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> g, s;
    int n;

    for (int i = 1; i < argc; i ++) {
        n = atoi(argv[i]);
        g.push_back(n);
    }

    while (cin >> n) {
        s.push_back(n);
    }

    cout << solution.findContentChildren(g, s) << endl;

    return 0;
}
