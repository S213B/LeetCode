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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **slow = &head, **fast = &head;

        while (n--)
            fast = &((*fast)->next);

        while (*fast) {
            fast = &((*fast)->next);
            slow = &((*slow)->next);
        }

        *slow = (*slow)->next;

        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int n = atoi(argv[1]);
    ListNode *head, **pp = &head;

    for (int i = 2; i < argc; i ++) {
        ListNode *new_node = new ListNode(atoi(argv[i]));
        *pp = new_node;
        pp = &new_node->next;
    }

    head = solution.removeNthFromEnd(head, n);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
