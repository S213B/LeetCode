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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);

        for (auto &b : bookings) {
            ans[b[0]-1] += b[2];
            if (b[1] < n)
                ans[b[1]] -= b[2];
        }

        for (int i = 1; i < n; i ++)
            ans[i] += ans[i-1];

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]), _n;
    vector<vector<int>> bookings;
    vector<int> booking, ans;

    while (cin >> _n) {
        booking.push_back(_n);
        if (booking.size() == 3) {
            bookings.push_back(booking);
            booking.clear();
        }
    }

    ans = solution.corpFlightBookings(bookings, n);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
