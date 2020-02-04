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

#if 0
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
#else
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        int i2 = 0, i3 = 0, i5 = 0;

        v[0] = 1;
        for (int i = 1; i < n; i ++) {
            v[i] = min(v[i2]*2, min(v[i3]*3, v[i5]*5));
            if (v[i] == v[i2]*2)
                i2 ++;
            if (v[i] == v[i3]*3)
                i3 ++;
            if (v[i] == v[i5]*5)
                i5 ++;
        }

        return v[n-1];
    }
};
#endif

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);

    cout << solution.nthUglyNumber(n) << endl;

    return 0;
}
