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
    int maximumSum(vector<int>& arr) {
        int ans = arr[0];
        int sum = arr[0];
        int neg_sum = min(arr[0], 0);
        int min_nb = min(arr[0], 0);

        for (int i = 1; i < arr.size(); i ++) {
            int n = arr[i];
            if (sum - min_nb < 0) {
                sum = n;
                neg_sum = min_nb = min(n, 0);
                ans = max(ans, n);
                continue;
            }
            neg_sum = min(neg_sum, sum);
            sum += n;
            ans = max(ans, sum - min_nb);
            if (neg_sum - min_nb + n < 0) {
                min_nb = n;
                sum -= neg_sum;
                neg_sum = 0;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> arr;

    for (int i = 1; i < argc; i ++)
        arr.push_back(atoi(argv[i]));

    cout << solution.maximumSum(arr) << endl;

    return 0;
}
