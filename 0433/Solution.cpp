#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    bool can_mutate(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i ++) {
            if (a[i] != b[i])
                diff ++;
        }
        return diff == 1;
    }

public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> visited(bank.size(), false);
        queue<string> q;
        int ans = 1;

        q.push(start);
        while (q.size()) {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i ++) {
                string from = q.front();
                q.pop();
                for (int j = 0; j < bank.size(); j ++) {
                    if (visited[j])
                        continue;
                    if (can_mutate(from, bank[j])) {
                        if (bank[j] == end)
                            return ans;
                        q.push(bank[j]);
                        visited[j] = true;
                    }
                }
            }
            ans ++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string start(argv[1]);
    string end(argv[2]);
    vector<string> bank;

    for (int i = 3; i < argc; i ++) {
        string s(argv[i]);
        bank.push_back(s);
    }

    cout << solution.minMutation(start, end, bank) << endl;

    return 0;
}
