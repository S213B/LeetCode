#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rev(int s, int e, int des, string &str) {
        reverse(str.begin()+s, str.begin()+e+1);
        for (int i = s; i <= e; i++) {
            str[des++] = str[i];
        }
    }

    void reverseWords(string &s) {
        string ans;
        int i = s.size() - 1;
        bool is_first = true;

        while (i >= 0) {
            int start, end;
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;
            end = i;
            while (i >= 0 && s[i] != ' ') i--;
            start = i;

            if (!is_first)
                ans += ' ';
            is_first = false;
            ans.append(s.begin()+start+1, s.begin()+end+1);
        }

        s = ans;
    }
};

int main()
{
    Solution slt;

    vector<string> str = {"l ", " l", "the sky is blue"};

    for (auto s : str) {
        cout << "input :\"" << s << '"' << endl;
        slt.reverseWords(s);
        cout << "output:\"" << s << '"' << endl;
    }

    return 0;
}
