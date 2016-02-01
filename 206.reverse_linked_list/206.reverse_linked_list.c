/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode *nextNode = head->next;
    int t = 0;
    while (nextNode != NULL) {
        struct ListNode *tmp = nextNode->next;
        nextNode->next = head;
        if (t == 0)
            head->next = NULL;
        head = nextNode;
        nextNode = tmp;
        t++;
    }
    return head;
}
