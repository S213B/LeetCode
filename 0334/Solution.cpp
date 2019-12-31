#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int stack[3], stack_sz = 0;

        for (auto n : nums) {
            if (!stack_sz) {
                stack[0] = n;
                stack_sz ++;
            } else if (stack_sz == 1) {
                if (n < stack[0]) {
                    stack[0] = n;
                } else if (n > stack[0]) {
                    stack[1] = n;
                    stack_sz ++;
                }
            } else if (stack_sz == 2) {
                if (n < stack[0]) {
                    stack[2] = n;
                    stack_sz ++;
                } else if (n > stack[0] && n < stack[1]) {
                    stack[1] = n;
                } else if (n > stack[1]) {
                    return true;
                }
            } else if (stack_sz == 3) {
                if (n < stack[2]) {
                    stack[2] = n;
                } else if (n > stack[2] && n < stack[1]) {
                    stack[0] = stack[2];
                    stack[1] = n;
                    stack_sz = 2;
                } else if (n > stack[1]) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    for (int i = 1; i < argc; i ++)
        nums.push_back(atoi(argv[i]));

    cout << solution.increasingTriplet(nums) << endl;

    return 0;
}
