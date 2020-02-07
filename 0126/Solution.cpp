#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
private:
    bool can_go(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i ++)
            diff += (a[i] == b[i] ? 0 : 1);
        return diff == 1;
    }

    void dfs(vector<string> &wordList, vector<vector<int>> &go, int cur, int end_idx, vector<vector<string>> &ans, vector<string> &an) {
        an.push_back(wordList[cur]);
        if (cur == end_idx) {
            ans.push_back(an);
            an.pop_back();
            return;
        }
        for (int i = 0; i < go[cur].size(); i ++)
            dfs(wordList, go, go[cur][i], end_idx, ans, an);
        an.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<int> not_visited;
        unordered_set<int> top_visited, down_visited, *self, *peer;
        vector<vector<int>> go(wordList.size()+1, vector<int>());
        bool done = false;
        vector<vector<string>> ans;

        int end_idx = -1, start_idx = -1;
        for (int i = 0; i < wordList.size(); i ++) {
            if (wordList[i] == endWord)
                end_idx = i;
            not_visited.insert(i);
        }
        if (end_idx < 0)
            return ans;

        if (start_idx < 0) {
            start_idx = wordList.size();
            wordList.push_back(beginWord);
        }
        top_visited.insert(start_idx);
        down_visited.insert(end_idx);

        while (top_visited.size() && down_visited.size() && !done) {
            bool top2down;
            if (top_visited.size() <= down_visited.size()) {
                self = &top_visited;
                peer = &down_visited;
                top2down = true;
            } else {
                self = &down_visited;
                peer = &top_visited;
                top2down = false;
            }

            unordered_set<int> visited_now;
            for (auto it = self->begin(); it != self->end(); it ++) {
                int n = *it;
                not_visited.erase(n);
            }
            for (auto from = self->begin(); from != self->end(); from ++) {
                int cur = *from;
                for (auto to = not_visited.begin(); to != not_visited.end(); to ++) {
                    int next = *to;
                    if (can_go(wordList[cur], wordList[next])) {
                        if (top2down)
                            go[cur].push_back(next);
                        else
                            go[next].push_back(cur);
                        if (peer->count(next))
                            done = true;
                        visited_now.insert(next);
                    }
                }
            }

            self->swap(visited_now);
        }

        vector<string> an;
        dfs(wordList, go, start_idx, end_idx, ans, an);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string beginWord(argv[1]);
    string endWord(argv[2]);
    vector<string> wordList;
    vector<vector<string>> ans;
    string word;

    while (cin >> word)
        wordList.push_back(word);

    ans = solution.findLadders(beginWord, endWord, wordList);

    for (auto &an : ans) {
        for (auto a : an)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
