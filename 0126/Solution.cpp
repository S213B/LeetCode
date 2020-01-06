#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

#if 1
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> path;
        vector<vector<string>> rc;
        unordered_set<string> s_top, s_bot, next_layer;
        bool is_end = false;

        if (!word.count(endWord))
            return rc;

        word.erase(beginWord);
        word.erase(endWord);

        s_top.insert(beginWord);
        s_bot.insert(endWord);

        while (!s_top.empty() && !s_bot.empty()) {
            unordered_set<string> *s1, *s2;
            bool is_top2bot = true;

            if (s_top.size() < s_bot.size()) {
                s1 = &s_top;
                s2 = &s_bot;
                is_top2bot = true;
            } else {
                s1 = &s_bot;
                s2 = &s_top;
                is_top2bot = false;
            }

            for (auto s = s1->begin(); s != s1->end(); s++) {
                string str = *s;
                for (char &c : str) {
                    const char orig = c;
                    for (c = 'a'; c < 'z'; c++) {
                        if (s2->count(str)) {
                            if (is_top2bot)
                                path[*s].push_back(str);
                            else
                                path[str].push_back(*s);
                            is_end = true;
                        } else if (!is_end && word.count(str)) {
                            if (is_top2bot)
                                path[*s].push_back(str);
                            else
                                path[str].push_back(*s);
                            next_layer.insert(str);
                        }
                    }
                    c = orig;
                }
            }

            if (is_end) break;

            for (const auto &s : next_layer) {
                word.erase(s);
            }

            s1->swap(next_layer);
            next_layer.clear();
        }

        if (is_end) {
            vector<string> t = {beginWord};
            gen_res(rc, path, path[beginWord], t, endWord);
        }

        return rc;
    }

    void gen_res(vector<vector<string>> &rc, unordered_map<string, vector<string>> &path, vector<string> &next, vector<string> p, string &end) {
        for (const auto &n : next) {
            p.push_back(n);
            if (n == end) {
                rc.push_back(p);
            } else if (path.count(n)) {
                gen_res(rc, path, path[n], p, end);
            }
            p.pop_back();
        }
    }
};
#else
class Solution {
private:
    bool can_transform(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i ++) {
            if (a[i] != b[i])
                diff ++;
        }
        return diff == 1;
    }

    void dfs(int idx, vector<vector<int>> &path, vector<string> &wordList, deque<string> &an, vector<vector<string>> &ans, string &beginWord) {
        if (idx == -1) {
            an.push_front(beginWord);
            ans.emplace_back(an.cbegin(), an.cend());
            an.pop_front();
            return;
        }
        an.push_front(wordList[idx]);
        for (int i = 0; i < path[idx].size(); i ++)
            dfs(path[idx][i], path, wordList, an, ans, beginWord);
        an.pop_front();
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        int word_sz = wordList.size();
        int end_idx = -1;
        vector<vector<bool>> can_go(word_sz, vector<bool>(word_sz));
        unordered_set<int> not_visited;
        vector<vector<int>> path(word_sz, vector<int>());
        queue<int> q;

        for (int i = 0; i < word_sz; i ++) {
            if (!endWord.compare(wordList[i]))
                end_idx = i;
            for (int j = i + 1; j < word_sz; j ++) {
                if (can_transform(wordList[i], wordList[j])) {
                    can_go[i][j] = can_go[j][i] = true;
                }
            }
            not_visited.insert(i);
        }
        if (end_idx == -1)
            return ans;

        for (int i = 0; i < word_sz; i ++) {
            if (can_transform(beginWord, wordList[i])) {
                q.push(i);
                not_visited.erase(i);
                path[i].push_back(-1);
            }
        }

        while (q.size() && !path[end_idx].size()) {
            vector<int> just_visited;
            int q_sz = q.size();
            for (int i = 0; i < q_sz; i ++) {
                int s = q.front();
                q.pop();
                for (auto j : not_visited) {
                    if (can_go[s][j]) {
                        if (!path[j].size())
                            q.push(j);
                        path[j].push_back(s);
                        just_visited.push_back(j);
                    }
                }
            }
            for (auto v : just_visited)
                not_visited.erase(v);
        }

        for (int i = 0; i < path[end_idx].size(); i ++) {
            deque<string> an{endWord};
            int j = path[end_idx][i];
            dfs(j, path, wordList, an, ans, beginWord);
        }

        return ans;
    }
};
#endif

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
            cout << a << endl;
        cout << endl;
    }

    return 0;
}
