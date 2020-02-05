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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *mid_prev = head, *tail = head;
        while (tail->next && tail->next->next) {
            tail = tail->next->next;
            mid_prev = mid_prev->next;
        }
        ListNode *mid = mid_prev->next;
        mid_prev->next = NULL;

        head = sortList(head);
        mid = sortList(mid);

        ListNode *ans = NULL, **pans = &ans;
        while (head && mid) {
            ListNode **n = head->val < mid->val ? &head : &mid;
            *pans = *n;
            pans = &((*pans)->next);
            *n = (*n)->next;
        }
        *pans = head ? head : mid;
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *head = NULL, **phead = &head;

    for (int i = 1; i < argc; i ++) {
        *phead = new ListNode(atoi(argv[i]));
        phead = &((*phead)->next);
    }

    head = solution.sortList(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
