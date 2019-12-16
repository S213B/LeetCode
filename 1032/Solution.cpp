#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class StreamChecker {
private:
    class trie {
    private:
        trie *next[26];
        bool end;
    public:
        trie(void) {
            memset(next, 0, sizeof(next));
            end = false;
        }
        trie *add(char ch) {
            int idx = ch - 'a';
            if (!next[idx])
                next[idx] = new trie();
            return next[idx];
        }
        trie *go(char ch) {
            int idx = ch - 'a';
            return next[idx];
        }
        bool is_end(void) {
            return end;
        }
        void set_end(void) {
            end = true;
        }
    };

    trie root;
    deque<char> data;
    int data_max;

public:
    StreamChecker(vector<string>& words) {
        data_max = -1;
        for (auto &word : words) {
            string s(word);
            reverse(s.begin(), s.end());
            trie *n = &root;
            for (auto c : s) {
                n = n->add(c);
            }
            n->set_end();
            if (s.size() > data_max)
                data_max = s.size();
        }
    }

    bool query(char letter) {
        data.push_front(letter);
        if (data.size() > data_max)
            data.pop_back();
        trie *n = &root;
        for (auto it = data.begin(); it != data.end(); it ++) {
            n = n->go(*it);
            if (!n)
                return false;
            if (n->is_end())
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    StreamChecker *checker;
    vector<string> words;
    char ch;

    for (int i = 1; i < argc; i ++) {
        string word(argv[i]);
        words.push_back(word);
    }

    checker = new StreamChecker(words);

    while (cin >> ch)
        cout << checker->query(ch) << endl;

    return 0;
}
