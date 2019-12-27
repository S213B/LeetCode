#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (!s1.size())
            return true;
        if (s1.size() == 1)
            return s1[0] == s2[0];
        for (int i = 1; i < s1.size(); i ++) {
            int s11[128] = {0}, s12[128] = {0};
            int s21[128] = {0}, s22[128] = {0}, s23[128] = {0}, s24[128] = {0};
            for (int j = 0; j < s1.size(); j ++) {
                if (j < i) {
                    s11[s1[j]] ++;
                    s21[s2[j]] ++;
                    s23[s2[s2.size()-1-j]] ++;
                } else {
                    s12[s1[j]] ++;
                    s22[s2[j]] ++;
                    s24[s2[s2.size()-1-j]] ++;
                }
            }
            if (!memcmp(s11, s21, sizeof(s11)) &&
                !memcmp(s12, s22, sizeof(s12))) {
                bool equal = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                             isScramble(s1.substr(i), s2.substr(i));
                if (equal)
                    return true;
            }
            if (!memcmp(s11, s23, sizeof(s11)) &&
                       !memcmp(s12, s24, sizeof(s12))) {
                bool equal = isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) &&
                             isScramble(s1.substr(i), s2.substr(0, s2.size()-i));
                if (equal)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s1(argv[1]);
    string s2(argv[2]);

    cout << solution.isScramble(s1, s2) << endl;

    return 0;
}
