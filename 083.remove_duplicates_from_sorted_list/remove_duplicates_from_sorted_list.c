/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) return head;
    struct ListNode *ans = head;
    struct ListNode *prev = head;
    int value = head->val;
    head = head->next;
    while (head != NULL) {
        if (head->val == value) {
            prev->next = head->next;
        } else {
            value = head->val;
            prev = head;
        }
        head = head->next;
    }
    return ans;
}
