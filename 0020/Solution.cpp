#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
private:
    char get_peer(char c) {
        switch (c) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '{':
            return '}';
        case '}':
            return '{';
        case '[':
            return ']';
        case ']':
            return '[';
        default:
            return 0;
        }
        return 0;
    }

public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (stk.size() && stk.top() == c)
                stk.pop();
            else
                stk.push(get_peer(c));
        }

        return stk.empty();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s(argv[1]);

    cout << solution.isValid(s) << endl;

    return 0;
}
