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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int visited_sz = 0;
        vector<bool> visited(n);
        queue<int> q;

        if (!rooms.size())
            return true;

        q.push(0);
        while (q.size()) {
            int key = q.front();
            q.pop();
            if (visited[key])
                continue;
            visited[key] = true;
            visited_sz ++;
            for (int i = 0; i < rooms[key].size(); i ++) {
                int new_key = rooms[key][i];
                if (visited[new_key])
                    continue;
                q.push(new_key);
            }
        }

        return visited_sz == n;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> rooms;
    vector<int> row;
    int n;

    while (cin >> n) {
        if (n < 0) {
            rooms.push_back(row);
            row.clear();
        } else {
            row.push_back(n);
        }
    }

    cout << solution.canVisitAllRooms(rooms) << endl;

    return 0;
}
