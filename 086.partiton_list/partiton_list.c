/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less = malloc(sizeof(struct ListNode));
    struct ListNode *great = malloc(sizeof(struct ListNode));
    struct ListNode *lessHead = less;
    struct ListNode *greatHead = great;
    less->val = 0;
    great->val = 0;
    less->next = NULL;
    great->next = NULL;
    while (head) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            great->next = head;
            great = great->next;
        }
        struct ListNode *tmp = head;
        head = head->next;
        tmp->next = NULL;
    }
    less->next = greatHead->next;
    return lessHead->next;
}
