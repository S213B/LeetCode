#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> same_on_right(ages.size(), 0);
        int ans = 0;

        sort(ages.begin(), ages.end());

        for (int i = ages.size()-2, j = 0; i >= 0; i --) {
            if (ages[i] != ages[i+1])
                j = 0;
            else
                j ++;
            same_on_right[i] = j;
        }

        for (int i = 0, l = 0; i < ages.size(); i ++) {
            int age = ages[i];
            int lower_limit = age / 2 + 7;
            while (l < ages.size() && ages[l] <= lower_limit) {
                l ++;
            }
            int h = i + same_on_right[i];
            //cout << l << " " << h << endl;
            if (h > l)
                ans += h - l;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> ages;

    for (int i = 1; i < argc; i ++) {
        int age = atoi(argv[i]);
        ages.push_back(age);
    }

    cout << solution.numFriendRequests(ages) << endl;

    return 0;
}
