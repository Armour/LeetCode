/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy;
    struct ListNode *p = &dummy;
    p->val = 0;
    p->next = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != NULL) {
        p->next = l1;
    }
    if (l2 != NULL) {
        p->next = l2;
    }
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    int len = listsSize;
    while (len > 1) {
        int k = (len + 1) / 2;
        for (int i = 0; i < len / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        len = k;
    }
    return lists[0];
}
