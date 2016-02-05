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
    bool checkValid(TreeNode *node, long min, long max) {
        if (node == NULL) return true;
        if (node->val <= min || node->val >= max) return false;
        return checkValid(node->left, min, node->val) && checkValid(node->right, node->val, max);
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        return checkValid(root->left, LONG_MIN, root->val) && checkValid(root->right, root->val, LONG_MAX);
    }
};
