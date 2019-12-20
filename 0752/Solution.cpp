#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> get_next(int cur) {
        vector<int> nexts;
        int tens[4] = {1, 10, 100, 1000};
        for (int i = 0; i < 4; i ++) {
            int ten = tens[i];
            int d = (cur / ten) % 10;
            int plus = (d == 9) ? (-9 * ten) : (1 * ten);
            int minus = (d == 0) ? (-9 * ten) : (1 * ten);
            nexts.push_back(cur + plus);
            nexts.push_back(cur - minus);
        }
        return nexts;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> path(10000, -1);
        queue<int> q;
        int end = stoi(target);

        for (auto &deadend : deadends) {
            int n = stoi(deadend);
            if (!n)
                return -1;
            path[n] = -2;
        }

        path[0] = 0;
        q.push(0);
        while (q.size()) {
            int cur = q.front();
            int step = path[cur] + 1;
            vector<int> nexts = get_next(cur);

            q.pop();

            for (auto next : nexts) {
                if (path[next] >= 0 || path[next] == -2)
                    continue;
                if (next == end)
                    return step;
                path[next] = step;
                q.push(next);
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> deadends;
    string target(argv[1]);

    for (int i = 2; i < argc; i ++) {
        string deadend(argv[i]);
        deadends.push_back(deadend);
    }

    cout << solution.openLock(deadends, target) << endl;

    return 0;
}
