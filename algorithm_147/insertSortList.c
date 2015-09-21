/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// int cmpfun(const void *a, const void *b) {
//     return *(int*)a-*(int*)b;
// }
struct ListNode* insertionSortList(struct ListNode* head) {
    int arr[5000], cnt = 0, i, j;
    struct ListNode* t = head;
    while(t != NULL) {
        arr[cnt++] = t->val;
        t = t->next;
    }
    for(i = 0; i < cnt-1; i++) {
        int min = i, t;
        for(j = i+1; j < cnt; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
    // qsort(arr, cnt, sizeof(int), cmpfun);
    for(i = 0, t = head; i < cnt; i++, t = t->next) {
        t->val = arr[i];
    }
    return head;
}
