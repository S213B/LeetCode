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
    char get_next(string &S, int &i, int &skip) {
        while (i >= 0) {
            if (S[i] == '#') {
                skip ++;
            } else if (skip) {
                skip --;
            } else {
                return S[i--];
            }
            i --;
        }

        return '\0';
    }

public:
    bool backspaceCompare(string S, string T) {
        int i1 = S.size()-1, skip1 = 0;
        int i2 = T.size()-1, skip2 = 0;

        while (i1 >= 0 || i2 >= 0) {
            char c1 = get_next(S, i1, skip1);
            char c2 = get_next(T, i2, skip2);

            if (c1 != c2)
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);
    string T(argv[2]);

    cout << solution.backspaceCompare(S, T) << endl;

    return 0;
}
