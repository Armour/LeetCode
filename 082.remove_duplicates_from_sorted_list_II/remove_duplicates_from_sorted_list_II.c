/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *nodeA = head;
    struct ListNode *nodeB = head->next;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy;
    dummy->val = 0;
    dummy->next = head;
    while (nodeB != NULL) {
        if (nodeA->val == nodeB->val) {
            struct ListNode *tmp = nodeB;
            while (nodeB != NULL && nodeB->val == nodeA->val) {
                nodeB = nodeB->next;
            }
            if (nodeB == NULL) {
                prev->next = NULL;
                break;
            }
            prev->next = nodeB;
            nodeA = nodeB;
        } else {
            prev = prev->next;
            nodeA = nodeA->next;
        }
        nodeB = nodeB->next;
    }
    return dummy->next;
}
