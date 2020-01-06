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
        int t;
        int i;
        node (int _t, int _i) : t(_t), i(_i) {}
    };

public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<node> stk;

        for (int i = 0; i < T.size(); i ++) {
            node n(T[i], i);
            while (stk.size()) {
                if (stk.top().t < n.t) {
                    node nn = stk.top();
                    stk.pop();
                    ans[nn.i] = n.i - nn.i;
                } else {
                    break;
                }
            }
            stk.push(n);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> T;
    vector<int> ans;

    for (int i = 1; i < argc; i ++)
        T.push_back(atoi(argv[i]));

    ans = solution.dailyTemperatures(T);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
