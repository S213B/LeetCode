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
private:
    struct node {
        int loc;
        int speed;
    };

    void move(struct node &n, bool A) {
        if (A) {
            n.loc += n.speed;
            n.speed *= 2;
        } else {
            if (n.speed > 0)
                n.speed = -1;
            else
                n.speed = 1;
        }
    }

public:
    int racecar(int target) {
        int ans = 0;
        struct node n = {0, 1};
        queue<struct node> q;
        unordered_map<int, unordered_set<int>> visited;
        int t_abs = target > 0 ? target : -target;

        q.push(n);
        while (q.size()) {
            int q_sz = q.size();
            cout << q_sz << endl;
            for (int i = 0; i < q_sz; i ++) {
                if (q.front().loc == target)
                    return ans;
                if (q.front().loc > t_abs * 2 || q.front().loc < 0) {
                    q.pop();
                    continue;
                }
                n = q.front();
                move(n, true);
                if (!visited.count(n.loc) || !visited[n.loc].count(n.speed)) {
                    q.push(n);
                    visited[n.loc].insert(n.speed);
                }
                n = q.front();
                move(n, false);
                if (!visited.count(n.loc) || !visited[n.loc].count(n.speed)) {
                    q.push(n);
                    visited[n.loc].insert(n.speed);
                }
                q.pop();
            }
            ans ++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int target = atoi(argv[1]);

    cout << solution.racecar(target) << endl;

    return 0;
}
