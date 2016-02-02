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

bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return true;
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
        if (st->val != head->val)
            return false;
        st = st->next;
        head = head->next;
    }
    return true;
}
