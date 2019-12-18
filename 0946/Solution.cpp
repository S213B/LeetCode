#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        if (!pushed.size())
            return true;

        stack<int> stk;
        int push_cnt = 0;

        for (int i = 0; i < popped.size(); i ++) {
            int to_pop = popped[i];
            while ((!stk.size() || stk.top() != to_pop) && push_cnt < pushed.size()) {
                int to_push = pushed[push_cnt];
                stk.push(to_push);
                push_cnt ++;
                if (to_push == to_pop)
                    break;
            }
            if (stk.size() && stk.top() == to_pop)
                stk.pop();
            else
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> pushed, popped;
    int num;

    for (int i = 1; i < argc; i ++) {
        num = atoi(argv[i]);
        pushed.push_back(num);
    }

    for (int i = 0; i < pushed.size(); i ++) {
        cin >> num;
        popped.push_back(num);
    }

    cout << solution.validateStackSequences(pushed, popped) << endl;

    return 0;
}
