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
    bool is_valid(string &s) {
        if (!s.size() || s.size() > 10 || (s.size() > 1 && s[0] == '0'))
            return false;
        long n = stol(s);
        if (n > 2147483647)
            return false;
        return true;
    }

    bool _splitIntoFibonacci(string S, vector<int> &ans, long a, long b) {
        if (!S.size())
            return true;
        long c = a + b;
        string cs = to_string(c);
        string ss = S.substr(0, cs.size());
        if (!is_valid(ss) || cs.compare(ss))
            return false;
        ans.push_back(c);
        if (_splitIntoFibonacci(S.substr(cs.size()), ans, b, c))
            return true;
        ans.pop_back();
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int S_sz = S.size();

        for (int i = 1; i < S_sz; i ++) {
            string s1 = S.substr(0, i);
            if (!is_valid(s1))
                continue;
            long n1 = stol(s1);
            ans.push_back(n1);
            for (int j = 1; j < S_sz-i; j ++) {
                string s2 = S.substr(i, j);
                if (!is_valid(s2))
                    continue;
                long n2 = stol(s2);
                ans.push_back(n2);
                if (_splitIntoFibonacci(S.substr(i+j), ans, n1, n2))
                    return ans;
                ans.pop_back();
            }
            ans.pop_back();
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string S(argv[1]);
    vector<int> ans;

    ans = solution.splitIntoFibonacci(S);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
