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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = new ListNode(0);
        ListNode *great = new ListNode(0);
        ListNode *lessHead = less;
        ListNode *greatHead = great;
        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                great->next = head;
                great = great->next;
            }
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
        }
        less->next = greatHead->next;
        return lessHead->next;
    }
};
