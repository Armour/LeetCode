/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (!head || k == 0) return head;

    int n = 1;
    struct ListNode *p = head;
    while (p->next) {
        p = p->next;
        n++;
    }

    k = n - k % n;
    p->next = head;

    for (int i = 0; i < k; i++) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;

    return head;
}
