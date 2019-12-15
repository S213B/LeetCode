#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    class helper{
    public:
        unordered_map<string, int> map, *target;
        queue<string> q;
        int max;
        int done_sz;
        helper(int max, unordered_map<string, int> *target) {
            this->max = max;
            this->target = target;
            this->done_sz = 0;
        }
        void pop(void) {
            string &s = q.front();
            map[s] --;
            if (map[s] == (*target)[s])
                done_sz ++;
            else if (map[s] == (*target)[s] - 1)
                done_sz --;
            q.pop();
        }
        void push(string &s) {
            if (q.size() == max)
                pop();
            map[s] ++;
            if (map[s] == (*target)[s])
                done_sz ++;
            else if (map[s] == (*target)[s] + 1)
                done_sz --;
            q.push(s);
        }
        int get_cnt(string &s) {
            return map[s];
        }
        bool done(void) {
            return done_sz == target->size();
        }
    };

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ss(s.size(), -1);
        queue<helper *> slide_window;
        unordered_map<string, int> word_cnt;
        int word_sz = words.size() ? words[0].size() : 0;
        vector<int> ans;

        if (!s.size() || !words.size())
            return ans;

        for (auto &word : words)
            word_cnt[word] ++;

        for (int i = 0; i < word_sz; i ++)
            slide_window.push(nullptr);

        for (int i = 0; i < words.size(); i++) {
            int start = 0, idx;
            while ((idx = s.find(words[i], start)) != string::npos) {
                ss[idx] = i;
                start = idx + 1;
            }
        }

        for (int i = 0; i < ss.size(); i ++) {
            helper *prev = slide_window.front();
            slide_window.pop();

            if (ss[i] == -1) {
                if (prev)
                    delete prev;
                slide_window.push(nullptr);
                continue;
            }

            string &word = words[ss[i]];
            if (!prev)
                prev = new helper(words.size(), &word_cnt);
            prev->push(word);
            if (prev->done())
                ans.push_back(i - (words.size()-1) * word_sz);
            slide_window.push(prev);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> words;
    vector<int> ans;
    string s(argv[1]);

    for (int i = 2; i < argc; i ++) {
        string word(argv[i]);
        words.push_back(word);
    }

    ans = solution.findSubstring(s, words);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
