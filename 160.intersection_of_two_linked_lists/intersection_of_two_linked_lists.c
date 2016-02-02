/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    struct ListNode *tailA = headA;
    while (tailA->next != NULL)
        tailA = tailA->next;
    tailA->next = headB;

    struct ListNode *slow = headA;
    struct ListNode *fast = headA;
    while (fast && (fast = fast->next) && (fast = fast->next)) {
        slow = slow->next;
        if (slow == fast) {
            struct ListNode *newSt = headA;
            while (newSt != slow) {
                newSt = newSt->next;
                slow = slow->next;
            }
            tailA->next = NULL;
            return newSt;
        }
    }
    tailA->next = NULL;
    return NULL;
}
