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
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int n = 0, i = 0;

        while (candies) {
            n ++;
            if (n > candies)
                n = candies;
            ans[i++] += n;
            candies -= n;
            if (i >= num_people)
                i = 0;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int candies = atoi(argv[1]);
    int num_people = atoi(argv[2]);
    vector<int> ans;

    ans = solution.distributeCandies(candies, num_people);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
