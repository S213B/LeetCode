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
        vector<int> bs(n), be(n);
        int b_sz = bookings.size();

        for (int i = 0; i < b_sz; i ++) {
            bs[bookings[i][0]-1] += bookings[i][2];
            be[bookings[i][1]-1] += bookings[i][2];
        }

        for (int i = 0, sum = 0; i < n; i ++) {
            sum += bs[i];
            ans[i] = sum;
            sum -= be[i];
        }

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
