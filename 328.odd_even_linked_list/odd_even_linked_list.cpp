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
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *odd, *even;
        ListNode *st_odd, *st_even;
        odd = head;
        even = head->next;
        st_odd = odd;
        st_even = even;
        head = head->next;
        int mark = 1;
        while (head->next != NULL) {
            head = head->next;
            if (mark) {
                odd->next = head;
                odd = odd->next;
                mark = 0;
            } else {
                even->next = head;
                even = even->next;
                mark = 1;
            }
        }
        odd->next = st_even;
        even->next = NULL;
        return st_odd;
    }
};
