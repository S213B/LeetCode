#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    bool go[20][20];
    unordered_map<int, int> visited;
    vector<uint32_t> loops;

    void dfs(int start, int loc, uint32_t steps) {
        for (int i = 0; i < 20; i ++) {
            if (!go[loc][i])
                continue;
            if (steps & (1 << i))
                break;
            uint32_t new_steps = steps | (1 << i);
            if (i == start) {
                if (!visited.count(new_steps)) {
                    visited[new_steps] = 1;
                    loops.push_back(new_steps);
                }
                break;
            }
            dfs(start, i, new_steps);
        }
    }

    void dfs(uint32_t cur_cover, int start) {
        int end = loops.size();
        for (int i = start; i < end; i ++) {
            uint32_t cover = loops[i];
            if (cur_cover & cover)
                continue;
            uint32_t new_cover = cur_cover | cover;
            int new_loop_cnt = visited[cur_cover] + visited[cover];
            if (!visited.count(new_cover))
                loops.push_back(new_cover);
            if (visited[new_cover] >= new_loop_cnt)
                continue;
            visited[new_cover] = new_loop_cnt;
            dfs(new_cover, end);
        }
    }

public:
    int kSimilarity(string A, string B) {
        int ans = 0;
        uint32_t end_mask = 0;
        memset(go, 0, sizeof(go));

        for (int i = 0; i < A.size(); i ++) {
            if (A[i] == B[i])
                continue;
            for (int j = 0; j < A.size(); j ++) {
                go[i][j] = (A[j] != B[j] && B[i] == A[j]);
            }
            end_mask |= 1 << i;
            ans ++;
        }

        for (int i = 0; i < A.size(); i ++) {
            if (A[i] == B[i])
                continue;
            dfs(i, i, 0);
        }

        int loop_sz = loops.size();
        for (int i = 0; i < loop_sz; i ++) {
            dfs(loops[i], 0);
        }

        return ans - visited[end_mask];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string A(argv[1]);
    string B(argv[2]);

    cout << solution.kSimilarity(A, B) << endl;

    return 0;
}
