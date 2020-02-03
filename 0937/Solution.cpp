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
    static bool my_sort(string &a, string &b) {
        int i = 0, j = 0, r;
        while (a[i] != ' ') i ++;
        while (b[j] != ' ') j ++;
        r = a.substr(i+1).compare(b.substr(j+1));
        if (r)
            return r < 0;
        return a.substr(0, i).compare(b.substr(0, j));
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;

        for (auto &log : logs) {
            int i = 0;
            while (log[i] != ' ') i ++;
            if (!isdigit(log[i+1]))
                ans.push_back(log);
        }

        sort(ans.begin(), ans.end(), my_sort);

        for (auto &log : logs) {
            int i = 0;
            while (log[i] != ' ') i ++;
            if (isdigit(log[i+1]))
                ans.push_back(log);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<string> logs, ans;
    string log;

#if 0
    while (cin >> log)
        logs.push_back(log);
#else
    logs.push_back("dig1 8 1 5 1");
    logs.push_back("let1 art can");
    logs.push_back("dig2 3 6");
    logs.push_back("let2 own kit dig");
    logs.push_back("let3 art zero");
#endif

    ans = solution.reorderLogFiles(logs);

    for (auto &an : ans)
        cout << an << endl;

    return 0;
}
