/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    while (prev->next && prev->next->next) {
        struct ListNode *node1 = prev->next;
        struct ListNode *node2 = prev->next->next;
        node1->next = node2->next;
        node2->next = node1;
        prev->next = node2;
        prev = node1;
    }
    return dummy.next;
}
