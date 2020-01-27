#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char map[256] = {0};
        
        for (int i = 0; i < 26; i ++)
            map[order[i]] = 'a' + i;

        for (auto &word : words) {
            for (auto &c : word)
                c = map[c];
        }

        for (int i = 1; i < words.size(); i ++) {
            if (words[i-1].compare(words[i]) > 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string order(argv[1]);
    vector<string> words;
    string word;

    assert(order.size() == 26);

    while (cin >> word)
        words.push_back(word);

    cout << solution.isAlienSorted(words, order) << endl;

    return 0;
}
