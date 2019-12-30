#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    bool can_transfer(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i ++) {
            if (a[i] != b[i])
                diff ++;
        }
        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        queue<int> q;
        int ans = 2;

        q.push(-1);
        while (q.size()) {
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i ++) {
                int from = q.front();
                q.pop();
                for (int j = 0; j < visited.size(); j ++) {
                    if (visited[j])
                        continue;
                    if (can_transfer(from == -1 ? beginWord : wordList[from], wordList[j])) {
                        q.push(j);
                        if (wordList[j] == endWord)
                            return ans;
                        visited[j] = true;
                    }
                }
            }
            ans ++;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string beginWord(argv[1]);
    string endWord(argv[2]);
    vector<string> wordList;

    for (int i = 3; i < argc; i ++) {
        string word(argv[i]);
        wordList.push_back(word);
    }

    cout << solution.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
