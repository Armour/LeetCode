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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int counter = 0;
        ListNode dummy(0);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = &dummy;
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
};
