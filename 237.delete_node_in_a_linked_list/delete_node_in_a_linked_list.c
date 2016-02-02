/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode *node) {
    struct ListNode *tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
}
