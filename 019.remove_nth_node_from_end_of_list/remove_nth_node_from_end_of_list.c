/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int counter = 0;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = malloc(sizeof(struct ListNode));
    prev->next = head;
    if (head->next == NULL && n == 1) return NULL;
    while (counter != n - 1) {
        fast = fast->next;
        counter++;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        prev = prev->next;
    }
    if (slow->next == NULL) {
        prev->next = NULL;
    } else {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
    }
    return head;
}
