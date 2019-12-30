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
    public:
        int x, y;
        point(int _x, int _y) : x(_x), y(_y) {}
    };

    bool dfs(vector<vector<int>> &A, int i, int j, vector<vector<bool>> &visited, queue<point *> &q) {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[i].size())
            return true;
        if (visited[i][j])
            return false;
        if (!A[i][j])
            return true;
        visited[i][j] = true;
        bool is_board = dfs(A, i-1, j, visited, q) |
                        dfs(A, i+1, j, visited, q) |
                        dfs(A, i, j+1, visited, q) |
                        dfs(A, i, j-1, visited, q);
        if (is_board)
            q.push(new point(i, j));
        return false;
    }

public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
        queue<point *> q;
        int ans = 0;

        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < A[i].size(); j ++) {
                if (A[i][j]) {
                    dfs(A, i, j, visited, q);
                    i = A.size();
                    break;
                }
            }
        }

        const int offset[8] = {-1, 0, 1, 0, 0, -1, 0, 1};
        while (q.size()) {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i ++) {
                point *p = q.front();
                q.pop();
                for (int j = 0; j < 8; j += 2) {
                    int xx = p->x + offset[j];
                    int yy = p->y + offset[j+1];
                    if (xx < 0 || yy < 0 || xx >= A.size() || yy >= A[xx].size())
                        continue;
                    if (visited[xx][yy])
                        continue;
                    if (A[xx][yy])
                        return ans;
                    q.push(new point(xx, yy));
                    visited[xx][yy] = true;
                }
            }
            ans ++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> A;
    vector<int> row;
    int row_sz = atoi(argv[1]);
    int n;

    while (cin >> n) {
        row.push_back(n);
        if (row.size() >= row_sz) {
            A.push_back(row);
            row.clear();
        }
    }

    cout << solution.shortestBridge(A) << endl;

    return 0;
}
