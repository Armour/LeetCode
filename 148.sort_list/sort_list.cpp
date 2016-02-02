/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;

        ListNode *l = sortList(head);
        ListNode *r = sortList(fast);

        return merge(l, r);
    }

    ListNode *merge(ListNode *a, ListNode *b) {
        if (!a) return b;
        if (!b) return a;
        ListNode m(0);
        ListNode *p = &m;
        while (a && b) {
            if (a->val < b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a)
           p->next = a;
        if (b)
           p->next = b;
        return m.next;
    }
};
