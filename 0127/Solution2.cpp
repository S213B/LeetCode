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
        vector<int> top_visited(wordList.size()+1, false), down_visited(wordList.size()+1, false), *self, *peer;
        vector<int> top, down, *v;
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
        top_visited[start_idx] = true;
        down_visited[end_idx] = true;
        top.push_back(start_idx);
        down.push_back(end_idx);

        while (top.size() && down.size()) {
            if (top.size() <= down.size()) {
                v = &top;
                self = &top_visited;
                peer = &down_visited;
                len = &top_len;
            } else {
                v = &down;
                self = &down_visited;
                peer = &top_visited;
                len = &down_len;
            }

            for (int i = 0; i < v->size(); i ++)
                visited[(*v)[i]] = true;

            vector<int> visit_now(wordList.size(), false);

            while (v->size()) {
                int curr = v->back();
                v->pop_back();
                for (int i = 0; i < visited.size(); i ++) {
                    if (!visited[i] && can_go(wordList[curr], wordList[i])) {
                        if ((*peer)[i])
                            return top_len + down_len;
                        visit_now[i] = true;
                        (*self)[i] = true;
                    }
                }
            }

            for (int i = 0; i < visit_now.size(); i ++) {
                if (visit_now[i])
                    v->push_back(i);
            }

            (*len) ++;
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
