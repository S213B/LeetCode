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
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> num2len;
        int ans = 1;

        for (auto n : arr) {
            int prev = n - difference;
            int len = 1;
            if (num2len.count(prev))
                len = num2len[prev] + 1;
            num2len[n] = len;
            ans = max(ans, len);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int difference = atoi(argv[1]);
    vector<int> arr;
    int n;

    while (cin >> n)
        arr.push_back(n);

    cout << solution.longestSubsequence(arr, difference) << endl;

    return 0;
}
