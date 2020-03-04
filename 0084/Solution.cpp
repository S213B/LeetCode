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
    struct node {
        int h, l, r;
        node(int _h, int _l, int _r) : h(_h), l(_l), r(_r) {};
        int get_sz(void) {
            return h * (r - l + 1);
        }
    };

public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack<node> stk;

        stk.push({0, -1, -1});
        heights.push_back(0);

        for (int i = 0; i <= n; i ++) {
            int h = heights[i];
            int l = i;
            while (stk.size() && stk.top().h >= h) {
                stk.top().r = i - 1;
                l = stk.top().l;
                ans = max(ans, stk.top().get_sz());
                stk.pop();
            }
            stk.push({h, l, i});
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> heights;

    for (int i = 1; i < argc; i ++)
        heights.push_back(atoi(argv[i]));

    cout << solution.largestRectangleArea(heights) << endl;

    return 0;
}
