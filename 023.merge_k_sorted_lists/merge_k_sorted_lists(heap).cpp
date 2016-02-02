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
    struct Comp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode*> &lists) {
        vector<ListNode*> heap;
        ListNode dummy(0);
        ListNode *ans = &dummy;
        ListNode *p = ans;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                heap.push_back(lists[i]);
        }
        make_heap(heap.begin(), heap.end(), Comp());
        while (!heap.empty()) {
            p->next = heap.front();
            p = p->next;
            pop_heap(heap.begin(), heap.end(), Comp());
            heap.pop_back();
            if (p->next != NULL) {
                heap.push_back(p->next);
                push_heap(heap.begin(), heap.end(), Comp());
            }
        }
        return ans->next;
    }
};
