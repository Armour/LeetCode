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
        if (head == NULL) return head;
        ListNode *ans = head;
        ListNode *prev = head;
        int value = head->val;
        head = head->next;
        while (head != NULL) {
            if (head->val == value) {
                prev->next = head->next;
            } else {
                value = head->val;
                prev = head;
            }
            head = head->next;
        }
        return ans;
    }
};
