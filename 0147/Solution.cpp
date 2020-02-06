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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ans = NULL;
        
        while (head) {
            ListNode **prev = &ans;
            while (*prev && (*prev)->val < head->val)
                prev = &((*prev)->next);
            ListNode *next = *prev;
            *prev = head;
            head = head->next;
            (*prev)->next = next;
        }

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

    head = solution.insertionSortList(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
