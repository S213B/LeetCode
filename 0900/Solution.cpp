#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class RLEIterator {
public:
    deque<int> cnt;
    deque<int> num;

    RLEIterator(vector<int>& A) {
        for (int i = 0; i < A.size(); i += 2) {
            int c = A[i];
            int n = A[i+1];
            cnt.push_back(c);
            num.push_back(n);
        }
    }

    int next(int n) {
        int ans = -1;
        while (n && cnt.size()) {
            if (n == cnt.front()) {
                ans = num.front();
                cnt.pop_front();
                num.pop_front();
                break;
            } else if (n > cnt.front()) {
                n -= cnt.front();
                cnt.pop_front();
                num.pop_front();
            } else {
                int left = cnt.front() - n;
                cnt.pop_front();
                cnt.push_front(left);
                ans = num.front();
                break;
            }
        }
        return ans;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */

int main(int argc, char *argv[]) {
    RLEIterator *iter;
    vector<int> nums;
    int nums_sz = atoi(argv[1]);
    int n;

    for (int i = 0; i < nums_sz; i ++) {
        cin >> n;
        nums.push_back(n);
    }
    if (nums.size() & 1)
        nums.push_back(1);

    iter = new RLEIterator(nums);

    while (cin >> n)
        cout << iter->next(n) << endl;

    return 0;
}
