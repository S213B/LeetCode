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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL, **pl = &ans;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                *pl = l1;
                l1 = l1->next;
            } else {
                *pl = l2;
                l2 = l2->next;
            }
            pl = &((*pl)->next);
        }
        *pl = l1 ? l1 : l2;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *l1 = NULL, *l2 = NULL, **pl, *ans;
    int n;

    pl = &l1;
    while (cin >> n) {
        if (n == -1)
            break;
        *pl = new ListNode(n);
        pl = &((*pl)->next);
    }

    pl = &l2;
    while (cin >> n) {
        if (n == -1)
            break;
        *pl = new ListNode(n);
        pl = &((*pl)->next);
    }

    ans = solution.mergeTwoLists(l1, l2);

    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}
