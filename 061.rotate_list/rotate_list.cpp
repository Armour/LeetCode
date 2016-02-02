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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;

        int n = 1;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            n++;
        }

        k = n - k % n;
        p->next = head;

        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;

        return head;
    }
};
