/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && (fast = fast->next) && (fast = fast->next)) {
        slow = slow->next;
        if (slow == fast) return true;
    }
    return false;
}
