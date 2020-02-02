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
        int len;
        int cnt;
        node(int l, int c) : len(l), cnt(c) {};
    };

public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<struct node> nodes(n, {1, 1});
        int ans = 0, max_len = 0;

        for (int i = n-1; i >= 0; i --) {
            for (int j = i + 1; j < n; j ++) {
                if (nums[i] < nums[j]) {
                    if (nodes[i].len < nodes[j].len + 1) {
                        nodes[i].cnt = nodes[j].cnt;
                        nodes[i].len = nodes[j].len + 1;
                    } else if (nodes[i].len == nodes[j].len + 1) {
                        nodes[i].cnt += nodes[j].cnt;
                    }
                }
            }
            if (nodes[i].len > max_len) {
                max_len = nodes[i].len;
                ans = nodes[i].cnt;
            } else if (nodes[i].len == max_len) {
                ans += nodes[i].cnt;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    cout << solution.findNumberOfLIS(nums) << endl;

    return 0;
}
