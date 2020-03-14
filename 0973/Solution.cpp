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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        priority_queue<int> max_heap;

        for (auto &p : points) {
            int dis = p[0] * p[0] + p[1] * p[1];
            max_heap.push(dis);
            if (max_heap.size() > K)
                max_heap.pop();
        }

        int max_dis = max_heap.top();
        for (auto &p : points) {
            int dis = p[0] * p[0] + p[1] * p[1];
            if (dis <= max_dis)
                ans.push_back(p);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> points, ans;
    int K = atoi(argv[1]), p1, p2;

    while (cin >> p1 && cin >> p2)
        points.push_back({p1, p2});

    ans = solution.kClosest(points, K);

    for (auto &an : ans)
        cout << an[0] << ',' << an[1] << endl;

    return 0;
}
