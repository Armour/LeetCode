/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge(struct ListNode *a, struct ListNode *b) {
    if (!a) return b;
    if (!b) return a;
    struct ListNode m;
    struct ListNode *p = &m;
    p->val = 0;
    p->next = NULL;
    while (a && b) {
        if (a->val < b->val) {
            p->next = a;
            a = a->next;
        } else {
            p->next = b;
            b = b->next;
        }
        p = p->next;
    }
    if (a)
       p->next = a;
    if (b)
       p->next = b;
    return m.next;
}

struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    struct ListNode *l = sortList(head);
    struct ListNode *r = sortList(fast);

    return merge(l, r);
}
