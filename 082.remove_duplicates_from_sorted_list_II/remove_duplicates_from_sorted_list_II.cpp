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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *nodeA = head;
        ListNode *nodeB = head->next;
        ListNode *prev = &dummy;
        while (nodeB != NULL) {
            if (nodeA->val == nodeB->val) {
                ListNode *tmp = nodeB;
                while (nodeB != NULL && nodeB->val == nodeA->val) {
                    nodeB = nodeB->next;
                }
                if (nodeB == NULL) {
                    prev->next = NULL;
                    break;
                }
                prev->next = nodeB;
                nodeA = nodeB;
            } else {
                prev = prev->next;
                nodeA = nodeA->next;
            }
            nodeB = nodeB->next;
        }
        return dummy.next;
    }
};
