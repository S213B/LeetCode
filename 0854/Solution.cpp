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
            uint32_t curr = loops[i];
            int j_end = loops.size();
            for (int j = 0; j < j_end; j++) {
                uint32_t peer = loops[j];
                if (curr & peer)
                    continue;
                uint32_t next = curr | peer;
                int loop_cnt = visited[curr] + visited[peer];
                if (!visited.count(next))
                    loops.push_back(next);
                if (visited[next] >= loop_cnt)
                    continue;
                visited[next] = loop_cnt;
            }
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
