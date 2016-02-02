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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(0);
        ListNode *res = &dummy;
        res->next = head;
        ListNode *prev = res;
        ListNode *current = head;
        while (current != NULL) {
            if (current->val == val) {
                current = current->next;
                prev->next = current;
            } else {
                current = current->next;
                prev = prev->next;
            }
        }
        return res->next;
    }
};
