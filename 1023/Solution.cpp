#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool is_upper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool is_match(string &query, string &pattern) {
        int i = 0;
        for (auto q : query) {
            if (i < pattern.size() && pattern[i] == q) {
                i ++;
            } else if (is_upper(q)) {
                return false;
            }
        }
        return i == pattern.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        for (auto &query : queries)
            ans.push_back(is_match(query, pattern));

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<bool> ans;
    vector<string> queries;
    string pattern(argv[1]);

    for (int i = 2; i < argc; i ++) {
        string query(argv[i]);
        queries.push_back(query);
    }

    ans = solution.camelMatch(queries, pattern);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
