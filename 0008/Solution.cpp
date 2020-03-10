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
    int myAtoi(string str) {
        int ans = 0, i = 0;
        bool is_neg = false;

        while (i < str.size() && str[i] == ' ') i ++;

        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            is_neg = (str[i] == '-');
            i ++;
        }

        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int c = str[i] - '0';
            if (!is_neg && ((INT_MAX - c) / 10 < ans))
                return INT_MAX;
            else if (is_neg && (INT_MIN + c) / 10 > ans)
                return INT_MIN;
            ans = ans * 10 + (is_neg ? -c : c);
            i ++;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string str(argv[1]);

    cout << solution.myAtoi(str) << endl;

    return 0;
}
