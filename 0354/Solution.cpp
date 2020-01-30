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
    bool can_fit_in(vector<int> &inside, vector<int> &outside) {
        return (outside[0] > inside[0] && outside[1] > inside[1]);
    }

    static bool my_cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> more(n, -1);
        int ans = 0;

        sort(envelopes.begin(), envelopes.end(), my_cmp);

        for (int i = n - 1; i >= 0; i --) {
            int outer = 0;
            for (int j = i + 1; j < n; j ++) {
                if (more[j] > outer && can_fit_in(envelopes[i], envelopes[j]))
                    outer = max(outer, more[j]);
            }
            more[i] = outer + 1;
            ans = max(ans, more[i]);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> envelopes;
    int n1, n2;

    while ((cin >> n1) && (cin >> n2)) {
        vector<int> row{n1, n2};
        envelopes.push_back(row);
    }

    cout << solution.maxEnvelopes(envelopes) << endl;

    return 0;
}
