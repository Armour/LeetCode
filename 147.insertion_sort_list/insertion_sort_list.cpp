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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        ListNode* p = &dummy;
        ListNode* current = head;
        while (current) {
            p = &dummy;
            while (p->next && p->next->val <= current->val) {
                p = p->next;
            }
            ListNode* n = p->next;
            p->next = current;
            current = current->next;
            p->next->next = n;
        }
        return dummy.next;
    }
};
