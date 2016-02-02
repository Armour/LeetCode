/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && (fast = fast->next) && (fast = fast->next)) {
        slow = slow->next;
        if (slow == fast) {
            struct ListNode *newSt = head;
            while (newSt != slow) {
                newSt = newSt->next;
                slow = slow->next;
            }
            return newSt;
        }
    }
    return NULL;
}
