#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MagicDictionary {
private:
    unordered_map<string, int> dic;
    unordered_set<string> ori_dic;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto &d : dict) {
            ori_dic.insert(d);
            for (int i = 0; i < d.size(); i++) {
                string new_d(d);
                new_d[i] = 1;
                dic[new_d] ++;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int min_cnt = ori_dic.count(word);
        for (int i = 0; i < word.size(); i++) {
            string new_word(word);
            new_word[i] = 1;
            if (dic[new_word] > min_cnt)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    MagicDictionary Dic;
    vector<string> words;
    string key;

    for (int i = 1; i < argc; i++) {
        string word(argv[i]);
        words.push_back(word);
    }

    Dic.buildDict(words);

    while (cin >> key)
        cout << Dic.search(key) << endl;

    return 0;
}
