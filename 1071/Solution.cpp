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
    string _gcdOfStrings(string str1, string str2) {
        if (!str2.size())
            return str1;
        int n1 = str1.size();
        int n2 = str2.size();
        int n3 = n1 % n2;
        return _gcdOfStrings(str2, str1.substr(n1-n3));
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if (!str2.size())
            return "";
        string s1 = str1.size() > str2.size() ? str1 : str2;
        string s2 = str1.size() > str2.size() ? str2 : str1;
        int i = 0;
        for (auto c : s1) {
            if (c != s2[i++])
                return "";
            if (i >= s2.size())
                i = 0;
        }
        return _gcdOfStrings(s1, s2);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string str1(argv[1]);
    string str2(argv[2]);

    cout << solution.gcdOfStrings(str1, str2) << endl;

    return 0;
}
