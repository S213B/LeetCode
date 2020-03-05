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
private:
    ListNode *_addTwoNumbers(ListNode *l1, int i1, ListNode *l2, int i2, int &c) {
        if (!l1 || !l2) {
            c = 0;
            return nullptr;
        }

        ListNode *node, *next;
        int v1 = 0, v2 = 0;

        if (i1 >= 0) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (i2 >= 0) {
            v2 = l2->val;
            l2 = l2->next;
        }

        next = _addTwoNumbers(l1, i1+1, l2, i2+1, c);
        v1 += v2 + c;
        node = new ListNode(v1 % 10);
        node->next = next;

        c = v1 / 10;
        return node;
    }

    int get_len(ListNode *l) {
        int len = 0;

        while (l) {
            l = l->next;
            len ++;
        }

        return len;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans;
        int n1, n2, n3, c;

        n1 = get_len(l1);
        n2 = get_len(l2);
        n3 = max(n1, n2);
        n1 -= n3;
        n2 -= n3;

        ans = _addTwoNumbers(l1, n1, l2, n2, c);

        if (c) {
            ListNode *head = new ListNode(1);
            head->next = ans;
            ans = head;
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    ListNode *l1, *l2, *ans;
    ListNode **p1 = &l1, **p2 = &l2;
    int n;

    while (cin >> n) {
        if (n < 0)
            break;
        *p1 = new ListNode(n);
        p1 = &((*p1)->next);
    }

    while (cin >> n) {
        if (n < 0)
            break;
        *p2 = new ListNode(n);
        p2 = &((*p2)->next);
    }

    ans = solution.addTwoNumbers(l1, l2);

    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}
