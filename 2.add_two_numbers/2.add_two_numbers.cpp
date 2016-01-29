/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *ans = new ListNode(0);
    ListNode *tail = ans;
    int last = 0;
public:
    void addNodeFromSum(int s) {
            ListNode *newNode = new ListNode(s % 10);
            tail->next = newNode;
            tail = newNode;
            last = s / 10;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != NULL && l2 != NULL) {
            addNodeFromSum(l1->val + l2->val + last);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            addNodeFromSum(l1->val + last);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            addNodeFromSum(l2->val + last);
            l2 = l2->next;
        }
        if (last != 0) {
            ListNode *newNode = new ListNode(last);
            tail->next = newNode;
            tail = newNode;
        }
        return ans->next;
    }
};
