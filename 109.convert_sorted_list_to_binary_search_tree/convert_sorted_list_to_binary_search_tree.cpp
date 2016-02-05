/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(ListNode *st, ListNode *ed) {
        if (st == ed) return NULL;
        ListNode *slow = st;
        ListNode *fast = st;
        while (fast && fast->next != ed && fast->next->next != ed) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *newNode = new TreeNode(slow->val);
        newNode->left = buildTree(st, slow);
        newNode->right = buildTree(slow->next, ed);
        return newNode;
    }

    TreeNode *sortedListToBST(ListNode* head) {
        return buildTree(head, NULL);
    }
};
