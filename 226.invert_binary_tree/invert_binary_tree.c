/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return root;
    struct TreeNode *leftNode = invertTree(root->left);
    struct TreeNode *rightNode = invertTree(root->right);
    root->left = rightNode;
    root->right = leftNode;
    return root;
}
