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
    int sumOfLL(TreeNode *node, int isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right) {
            if (isLeft)
                return node->val;
            else
                return 0;
        }
        return sumOfLL(node->left, true) + sumOfLL(node->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return sumOfLL(root->left, true) + sumOfLL(root->right, false);
    }
};
