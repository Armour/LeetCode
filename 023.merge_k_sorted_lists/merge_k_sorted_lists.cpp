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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != NULL) {
            p->next = l1;
        }
        if (l2 != NULL) {
            p->next = l2;
        }
        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty())
            return NULL;

        int len = lists.size();
        while (len > 1) {
            int k = (len + 1) / 2;
            for (int i = 0; i < len / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            len = k;
        }
        return lists[0];
    }
};
