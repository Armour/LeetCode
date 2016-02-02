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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode *tailA = headA;
        while (tailA->next != NULL)
            tailA = tailA->next;
        tailA->next = headB;

        ListNode *slow = headA;
        ListNode *fast = headA;
        while (fast && (fast = fast->next) && (fast = fast->next)) {
            slow = slow->next;
            if (slow == fast) {
                ListNode *newSt = headA;
                while (newSt != slow) {
                    newSt = newSt->next;
                    slow = slow->next;
                }
                tailA->next = NULL;
                return newSt;
            }
        }
        tailA->next = NULL;
        return NULL;
    }
};
