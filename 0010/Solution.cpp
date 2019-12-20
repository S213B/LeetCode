#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool ch_match(char c, char p) {
        return c == p || p == '.';
    }

    void print(vector<vector<bool>> match) {
        for (int i = 0; i < match.size(); i ++) {
            for (int j = 0; j < match[i].size(); j ++)
                cout << match[i][j] << " ";
            cout << endl;
        }
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(s.size(), vector<bool>(p.size(), false));

        if (!p.size())
            return s.empty();

        match[0][0] = ch_match(s[0], p[0]);
        for (int i = 1; i < p.size(); i ++) {
            if ((i != p.size()-1 && p[i+1] == '*') || p[i] == '*')
                match[0][i] = match[0][i-1];
            else
                match[0][i] = false;
        }

        for (int i = 1; i < s.size(); i ++) {
            for (int j = 1; j < p.size(); j ++) {
                if (ch_match(s[i], p[j])) {
                    match[i][j] = match[i-1][j-1];
                } else if (p[j] != '*') {
                    match[i][j] = false;
                } else {
                    match[i][j] = match[i][j] | match[i][j-1];
                    if (j >= 2)
                        match[i][j] = match[i][j] | match[i][j-2];
                }
            }
        }

        //print(match);

        return match[s.size()-1][p.size()-1];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);
    string p(argv[2]);

    cout << "string :" << s << endl;
    cout << "pattern:" << p << endl;

    cout << solution.isMatch(s, p) << endl;

    return 0;
}
