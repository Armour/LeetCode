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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) return head;

        ListNode dummy(0);
        ListNode *prev = &dummy;
        ListNode *start = head;
        prev->next = head;
        int counter = 0;
        while (counter < m - 1) {
            start = start->next;
            prev = prev->next;
            counter++;
        }

        ListNode *currentNode = start;
        ListNode *nextNode = currentNode->next;
        int t = 0;
        while (t != n - m) {
            ListNode *tmp = nextNode->next;
            nextNode->next = currentNode;
            currentNode = nextNode;
            nextNode = tmp;
            t++;
        }
        prev->next = currentNode;
        start->next = nextNode;
        return dummy.next;
    }
};
