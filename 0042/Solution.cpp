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
        int w, h;
        node(int _h, int _w) : h(_h), w(_w) {};
    };
    
public:
    int trap(vector<int>& height) {
        int ans = 0, high = 0, low = 0;
        stack<node> stk;

        for (int i = 0; i < height.size(); i ++) {
            int h = height[i];
            if (h <= low) {
                stk.push({h, 1});
                low = h;
            } else if (h <= high) {
                int w = 1;
                while (stk.size() && stk.top().h <= h) {
                    ans += stk.top().w * (h - stk.top().h);
                    w += stk.top().w;
                    stk.pop();
                }
                stk.push({h, w});
                low = h;
            } else {
                while (stk.size()) {
                    ans += stk.top().w * (high - stk.top().h);
                    stk.pop();
                }
                stk.push({h, 1});
                high = low = h;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> height;

    for (int i = 1; i < argc; i ++)
        height.push_back(atoi(argv[i]));

    cout << solution.trap(height) << endl;

    return 0;
}
