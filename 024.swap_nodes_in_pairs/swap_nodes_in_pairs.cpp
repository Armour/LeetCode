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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode *node1 = prev->next;
            ListNode *node2 = prev->next->next;
            node1->next = node2->next;
            node2->next = node1;
            prev->next = node2;
            prev = node1;
        }
        return dummy.next;
    }
};
