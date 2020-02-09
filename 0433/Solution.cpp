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
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> not_visited(bank.begin(), bank.end());
        unordered_set<string> top, down, *self, *peer;
        const char alpha[] = {'A', 'C', 'G', 'T'};
        int ans = 1;

        if (!not_visited.count(end))
            return -1;

        top.insert(start);
        down.insert(end);

        while (top.size() && down.size()) {
            self = top.size() <= down.size() ? &top : &down;
            peer = top.size() <= down.size() ? &down : &top;

            unordered_set<string> next;

            for (auto it = self->begin(); it != self->end(); it ++) {
                string curr = *it;
                for (int i = 0; i < curr.size(); i ++) {
                    int c = curr[i];
                    for (int j = 0; j < sizeof(alpha); j ++) {
                        curr[i] = alpha[j];
                        if (peer->count(curr))
                            return ans;
                        else if (not_visited.count(curr)) {
                            not_visited.erase(curr);
                            next.insert(curr);
                        }
                    }
                    curr[i] = c;
                }
            }

            self->swap(next);
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
