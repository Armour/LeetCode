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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && (fast = fast->next) && (fast = fast->next)) {
            slow = slow->next;
            if (slow == fast) {
                ListNode *newSt = head;
                while (newSt != slow) {
                    newSt = newSt->next;
                    slow = slow->next;
                }
                return newSt;
            }
        }
        return NULL;
    }
};
