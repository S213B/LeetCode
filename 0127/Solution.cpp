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
    bool can_go(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i ++)
            diff += (a[i] == b[i]) ? 0 : 1;
        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        bool done = false;
        unordered_set<int> top, down, *self, *peer;
        int top_len = 1, down_len = 1, *len;
        int ans = 0;

        int start_idx = -1, end_idx = -1;
        for (int i = 0; i < wordList.size(); i ++) {
            if (wordList[i] == endWord)
                end_idx = i;
            if (wordList[i] == beginWord)
                start_idx = i;
        }
        if (end_idx < 0)
            return 0;
        if (start_idx < 0) {
            start_idx = wordList.size();
            wordList.push_back(beginWord);
            visited.push_back(false);
        }
        top.insert(start_idx);
        down.insert(end_idx);

        while (top.size() && down.size() && !done) {
            bool top2down;
            if (top.size() <= down.size()) {
                self = &top;
                peer = &down;
                len = &top_len;
                top2down = true;
            } else {
                self = &down;
                peer = &top;
                len = &down_len;
                top2down = false;
            }
            for (auto it = self->begin(); it != self->end(); it ++)
                visited[*it] = true;

            unordered_set<int> visit_now;
            for (auto it = self->begin(); it != self->end(); it ++) {
                int curr = *it;
                for (int i = 0; i < visited.size(); i ++) {
                    if (!visited[i] && can_go(wordList[curr], wordList[i])) {
                        visit_now.insert(i);
                        if (peer->count(i)) {
                            done = true;
                            ans = top_len + down_len;
                        }
                    }
                }
            }

            (*len) ++;
            self->swap(visit_now);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string beginWord(argv[1]);
    string endWord(argv[2]);
    vector<string> wordList;
    string word;

    while (cin >> word)
        wordList.push_back(word);

    cout << solution.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
