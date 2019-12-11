#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool is_subseq(vector<vector<int>> &S_chs_idx, const string &word) {
        int S_cur_idx = -1;

        for (int i = 0; i < word.size(); i ++) {
            vector<int> &S_ch_idx = S_chs_idx[word[i] - 'a'];
            int j = 0;
            while (j < S_ch_idx.size() ) {
                if (S_ch_idx[j] > S_cur_idx)
                    break;
                j ++;
            }

            if (j == S_ch_idx.size())
                return false;

            S_cur_idx = S_ch_idx[j];
        }

        return true;
    }

public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> S_chs_idx;
        int ans = 0;

        for (int i = 0; i < 26; i ++) {
            vector<int> v;
            S_chs_idx.push_back(v);
        }

        for (int i = 0; i < S.size(); i ++) {
            int idx = S[i] - 'a';
            S_chs_idx[idx].push_back(i);
        }

#if 0
        unordered_map<string, int> uniq_words;

        for (auto &word : words)
            uniq_words[word] ++;

        for (auto &word: uniq_words) {
            if (is_subseq(S_chs_idx, word.first))
                ans += word.second;
        }
#else
        for (auto &word: words) {
            if (is_subseq(S_chs_idx, word))
                ans ++;
        }
#endif

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);
    vector<string> words;

    for (int i = 2; i < argc; i ++) {
        string word(argv[i]);
        words.push_back(word);
    }

    cout << solution.numMatchingSubseq(S, words) << endl;

    return 0;
}
