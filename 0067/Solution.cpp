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
    string addBinary(string a, string b) {
        string ans;
        int i = 0, j = 0, c = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (i < a.size() || j < b.size() || c) {
            int na = (i < a.size()) ? a[i] - '0' : 0;
            int nb = (j < b.size()) ? b[i] - '0' : 0;
            int nn = (na + nb + c) & 1;
            c = (na + nb + c) >> 1;

            ans.push_back(nn ? '1' : '0');

            i ++, j ++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string a(argv[1]);
    string b(argv[2]);

    cout << solution.addBinary(a, b) << endl;

    return 0;
}
