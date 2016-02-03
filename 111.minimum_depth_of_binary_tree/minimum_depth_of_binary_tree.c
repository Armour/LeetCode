/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a, int b) {
    return a > b? b: a;
}

int minDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int left = INT_MAX;
    int right = INT_MAX;
    if (root->left != NULL)
        left = minDepth(root->left);
    if (root->right != NULL)
        right = minDepth(root->right);
    return min(left, right) + 1;
}
