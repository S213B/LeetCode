#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tol_steps = 0;
        int tol_dis = gas.size();
        int start = 0, loc = 0;
        int gas_left = gas[0];

        while (tol_steps < tol_dis * 2) {
            gas_left -= cost[loc];
            loc ++;
            if (loc == tol_dis)
                loc = 0;
            if (gas_left >= 0) {
                if (loc == start)
                    return start;
                gas_left += gas[loc];
            } else {
                gas_left = gas[loc];
                start = loc;
            }
            tol_steps ++;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> gas, cost;
    int sz = (argc - 1) / 2;

    for (int i = 0; i < sz; i ++)
        gas.push_back(atoi(argv[1+i]));

    for (int i = 0; i < sz; i ++)
        cost.push_back(atoi(argv[1+sz+i]));

    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
