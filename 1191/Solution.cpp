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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long r = 1000000007;
        long sum = 0, l2r = 0, r2l = 0;
        long ans = 0;

        for (long i = 0, s = 0; i < arr.size(); i ++) {
            s += arr[i];
            if (s < 0)
                s = 0;
            ans = max(ans, s);
        }

        for (long i = 0; i < arr.size(); i ++) {
            sum += arr[i];
            l2r = max(l2r, sum);
        }

        for (long i = arr.size()-1, s = 0; i >= 0; i --) {
            s += arr[i];
            r2l = max(r2l, s);
        }
        //cout << l2r << " " << r2l << " " << sum << endl;

        if (k >= 2)
            ans = max(ans, l2r + r2l);
        if (k > 2 && sum > 0)
            ans = max(ans, l2r + r2l + sum * (k - 2));

        return ans % r;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int k = atoi(argv[1]);
    vector<int> arr;

    for (int i = 2; i < argc; i ++)
        arr.push_back(atoi(argv[i]));

    cout << solution.kConcatenationMaxSum(arr, k) << endl;

    return 0;
}
