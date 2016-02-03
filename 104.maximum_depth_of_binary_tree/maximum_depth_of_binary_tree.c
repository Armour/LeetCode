/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b? a: b;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int left = 0;
    int right = 0;
    if (root->left != NULL)
        left = maxDepth(root->left);
    if (root->right != NULL)
        right = maxDepth(root->right);
    return max(left, right) + 1;
}
