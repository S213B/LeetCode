#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> s;
        int cnt = 0;

        s.insert(1);
        while (cnt + 1 < n) {
            long n = *s.begin();
            s.erase(s.begin());
            s.insert(n*2);
            s.insert(n*3);
            s.insert(n*5);
            cnt ++;
        }

        return *s.begin();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);

    cout << solution.nthUglyNumber(n) << endl;

    return 0;
}
