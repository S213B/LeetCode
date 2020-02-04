#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* _merge(ListNode *n1, ListNode *n2) {
        ListNode *n = NULL, **nn = &n;
        while (n1 && n2) {
            if (n1->val < n2->val) {
                *nn = n1;
                n1 = n1->next;
            } else {
                *nn = n2;
                n2 = n2->next;
            }
            nn = &((*nn)->next);
        }
        *nn = n1 ? n1 : n2;
        return n;
    }

    ListNode* _mergeKLists(vector<ListNode*>& lists, int s, int e) {
        if (s == e)
            return lists[s];
        int m = s + (e - s) / 2;
        ListNode *n1 = _mergeKLists(lists, s, m);
        ListNode *n2 = _mergeKLists(lists, m+1, e);
        return _merge(n1, n2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return NULL;
        return _mergeKLists(lists, 0, lists.size()-1);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<ListNode *> lists;
    ListNode *list = NULL, **plist = &list;
    int n;

    while (cin >> n) {
        if (n == -1) {
            lists.push_back(list);
            plist = &list;
        } else {
            *plist = new ListNode(n);
            plist = &((*plist)->next);
        }
    }

    list = solution.mergeKLists(lists);

    while (list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;

    return 0;
}
