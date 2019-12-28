#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    class point {
    private:
        int x, y;
    public:
        point(int _x, int _y) : x(_x), y(_y) {}
        int get_x(void) {
            return x;
        }
        int get_y(void) {
            return y;
        }
    };

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 1, grid_sz = grid.size();
        queue<point *> q;

        q.push(new point(0, 0));
        while (q.size()) {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i ++) {
                point *p = q.front();
                int x = p->get_x();
                int y = p->get_y();

                q.pop();

                if (x < 0 || y < 0 || x >= grid_sz || y >= grid_sz)
                    continue;

                if (grid[x][y])
                    continue;

                if (x == grid_sz-1 && y == grid_sz-1)
                    return ans;

                grid[x][y] = 2;

                q.push(new point(x-1, y-1));
                q.push(new point(x-1, y));
                q.push(new point(x-1, y+1));
                q.push(new point(x, y-1));
                q.push(new point(x, y+1));
                q.push(new point(x+1, y-1));
                q.push(new point(x+1, y));
                q.push(new point(x+1, y+1));
            }
            ans ++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> grid;
    int sz = atoi(argv[1]), n;

    for (int i = 0; i < sz; i ++) {
        vector<int> row;
        for (int j = 0; j < sz; j ++) {
            cin >> n;
            row.push_back(n);
        }
        grid.push_back(row);
    }

    cout << solution.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
