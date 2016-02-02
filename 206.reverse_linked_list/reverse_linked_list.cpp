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
};
