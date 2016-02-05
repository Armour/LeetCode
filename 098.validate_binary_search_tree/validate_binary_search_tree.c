/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkValid(struct TreeNode *node, long min, long max) {
    if (node == NULL) return true;
    if (node->val <= min || node->val >= max) return false;
    return checkValid(node->left, min, node->val) && checkValid(node->right, node->val, max);
}

bool isValidBST(struct TreeNode *root) {
    if (root == NULL) return true;
    return checkValid(root->left, LONG_MIN, root->val) && checkValid(root->right, root->val, LONG_MAX);
}
