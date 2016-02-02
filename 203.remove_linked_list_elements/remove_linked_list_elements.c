/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode *res = malloc(sizeof(struct ListNode));
    res->val = 0;
    res->next = head;
    struct ListNode *prev = res;
    struct ListNode *current = head;
    while (current != NULL) {
        if (current->val == val) {
            current = current->next;
            prev->next = current;
        } else {
            current = current->next;
            prev = prev->next;
        }
    }
    return res->next;
}
