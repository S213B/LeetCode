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
    int leastInterval(vector<char>& tasks, int n) {
        int map[256] = {0};
        int most = 0, most_cnt = 0, ans = 0;

        for (char t : tasks) {
            map[t] ++;
            if (map[t] > most) {
                most = map[t];
                most_cnt = 1;
            } else if (map[t] == most) {
                most_cnt ++;
            }
        }

        ans = (most - 1) * (n + 1) + most_cnt;
        int left = tasks.size() - most * most_cnt;
        left -= (most - 1) * (n + 1 - most_cnt);
        if (left > 0)
            ans += left;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<char> tasks;
    int n = atoi(argv[1]);
    char c;

    while (cin >> c)
        tasks.push_back(c);

    cout << solution.leastInterval(tasks, n) << endl;

    return 0;
}
