#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
private:
    void helper(vector<string> &v, int k) {
        unordered_set<string> set;

        if (!k) {
            v.push_back("");
            return;
        }

        helper(v, k-1);

        for (auto &s : v) {
            for (int i = 0; i <= s.size(); i++) {
                string ss(s);
                ss.insert(ss.begin() + i, '(');
                for (int j = i+1; j <= ss.size(); j++) {
                    string sss(ss);
                    sss.insert(sss.begin() + j, ')');
                    set.insert(sss);
                }
            }
        }

        v.clear();
        v.assign(set.begin(), set.end());
    }

public:
    vector<string> go(int k) {
        vector<string> ans;

        helper(ans, k);

        return ans;
    }
};

bool is_pair(char a, char b) {
    return a == '(' && b == ')';
}

bool is_valid(string &s) {
    stack<char> stack;

    for (auto c : s) {
        if (stack.size() && is_pair(stack.top(), c)) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    return stack.empty();
}

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> v;

    for (int i = 0; i < atoi(argv[1]); i++) {
        v = solution.go(i);

        for (auto &s : v) {
            if (!is_valid(s)) {
                cout << s << endl;
                break;
            }
        }
    }

    return 0;
}
