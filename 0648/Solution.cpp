#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    class node {
    public:
        node *next[26];
        bool end;
        node (void) {
            memset(next, 0, sizeof(next));
            end = false;
        }
        node *add(char c) {
            int i = c - 'a';
            if (!next[i])
                next[i] = new node;
            return next[i];
        }
    };

    int find_key(node *root, string &s, int start_idx, int end_idx) {
        node *n = root;
        int si = start_idx;
        int ei = end_idx;
        while (si != ei) {
            n = n->next[s[si] - 'a'];
            if (!n)
                return end_idx - start_idx;
            if (n->end)
                return si - start_idx + 1;
            si ++;
        }
        return end_idx - start_idx;
    }

    void add_key(node *root, string &key) {
        node *n = root;
        for (auto k : key)
            n = n->add(k);
        n->end = true;
    }

public:
    string replaceWords(vector<string>& dict, string sentence) {
        node root;
        string ans;
        int i;
        
        for (auto &d : dict)
            add_key(&root, d);

        i = 0;
        while (i < sentence.size()) {
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ') j++;
            int new_len = find_key(&root, sentence, i, j);
            if (i)
                ans.push_back(' ');
            ans += sentence.substr(i, new_len);
            i = j + 1;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> dict;
    string sentence;
    string ans;
    int i;

    for (i = 2; i < atoi(argv[1]) + 2; i ++) {
        string d(argv[i]);
        dict.push_back(d);
    }
    for (; i < argc; i ++) {
        sentence.append(argv[i]);
        sentence.push_back(' ');
    }
    sentence.pop_back();

    ans = solution.replaceWords(dict, sentence);

    cout << ans << endl;

    return 0;
}
