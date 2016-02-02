/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
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

void reorderList(struct ListNode *head) {
    if (head != NULL && head->next != NULL) {
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        struct ListNode *st = slow->next;
        slow->next = NULL;

        st = reverseList(st);

        while (st != NULL) {
            struct ListNode *current = head;
            struct ListNode *nextNode = head->next;
            if (st != NULL) {
                struct ListNode *tmp = st->next;
                current -> next = st;
                st->next = nextNode;
                st = tmp;
            }
            head = head->next->next;
        }
    }
}
