#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rev(int s, int e, int des, string &str) {
#if 0
        int cnt = (e-s+1)/2;
        for (int i = 0; i < cnt; i++) {
            const char c = str[s+i];
            str[s+i] = str[e-i];
            str[e-i] = c;
        }
#else
        reverse(str.begin()+s, str.begin()+e+1);
#endif
        for (int i = s; i <= e; i++) {
            str[des++] = str[i];
        }
    }

    void reverseWords(string &s) {
        int sz = s.size(), _s = 0, _e = 0;
        int des = 0, end = 0;

        if (s.find(' ') == string::npos) return;

#if 0
        rev(0, sz-1, 0, s);
#else
        reverse(s.begin(), s.end());
#endif

        for (int i = 0; i < sz;) {
            while (i < sz && s[i] == ' ') i++;
            if (i == sz) break;
            _s = i;
            while (i < sz && s[i] != ' ') i++;
            _e = i;
            rev(_s, _e-1, des, s);
            des += _e - _s + 1; // des: next word start pos
            //cout << "des:" << des << endl;
            end = des - 1;
            if (end < sz) s[end] = ' ';
            //cout << des << " " << _s << " " << _e << " " << sz << endl;
        }

        s.resize(end);
        //cout << end << endl;
        //cout << s[s.size()-1]  << endl;
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
