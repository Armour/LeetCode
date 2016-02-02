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
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) return head;
        ListNode *nextNode = head->next;
        int t = 0;
        while (nextNode != NULL) {
            ListNode *tmp = nextNode->next;
            nextNode->next = head;
            if (t == 0)
                head->next = NULL;
            head = nextNode;
            nextNode = tmp;
            t++;
        }
        return head;
    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *st = slow->next;
        slow->next = NULL;

        st = reverseList(st);

        while (st != NULL) {
            if (st->val != head->val)
                return false;
            st = st->next;
            head = head->next;
        }
        return true;
    }
};
