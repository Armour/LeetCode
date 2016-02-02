/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *ans = &dummy;
    struct ListNode *tail = ans;
    int carry = 0;
    ans->val = 0;
    ans->next = NULL;
    while (l1 || l2 || carry) {
        if (l1 != NULL) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            carry += l2->val;
            l2 = l2->next;
        }
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = carry % 10;
        tail->next = tmp;
        carry /= 10;
        tail = tail->next;
    }
    return ans->next;
}
