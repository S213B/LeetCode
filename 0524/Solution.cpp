#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool convertable(string &from, string &to) {
        int i = 0;
        if (from.size() < to.size())
            return false;
        if (!to.size())
            return true;
        for (auto c : from) {
            if (c == to[i]) {
                i ++;
                if (i == to.size())
                    return true;
            }
        }
        return false;
    }

public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";

        for (auto &ds : d) {
            if (!convertable(s, ds) || ds.size() < ans.size())
                continue;
            if (ds.size() > ans.size())
                ans = ds;
            else if (ds.compare(ans) < 0)
                ans = ds;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    vector<string> d;
    string ans;

    for (int i = 2; i < argc; i++) {
        string dd(argv[i]);
        d.push_back(dd);
    }

    ans = solution.findLongestWord(s, d);

    cout << ans << endl;

    return 0;
}
