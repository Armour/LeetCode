/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    if (head == NULL) return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy;
    struct ListNode *start = head;
    prev->next = head;
    int counter = 0;
    while (counter < m - 1) {
        start = start->next;
        prev = prev->next;
        counter++;
    }

    struct ListNode *currentNode = start;
    struct ListNode *nextNode = currentNode->next;
    int t = 0;
    while (t != n - m) {
        struct ListNode *tmp = nextNode->next;
        nextNode->next = currentNode;
        currentNode = nextNode;
        nextNode = tmp;
        t++;
    }
    prev->next = currentNode;
    start->next = nextNode;
    return dummy->next;
}
