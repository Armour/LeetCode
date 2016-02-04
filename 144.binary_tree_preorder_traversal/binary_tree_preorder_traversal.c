/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traversal(struct TreeNode *node, int *preorder, int *counter) {
    if (node == NULL) return;
    preorder[(*counter)++] = node->val;
    preorder = realloc(preorder, sizeof(int) * (*counter + 1));
    traversal(node->left, preorder, counter);
    traversal(node->right, preorder, counter);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *preorder = malloc(sizeof(int));
    int counter = 0;
    traversal(root, preorder, &counter);
    *returnSize = counter;
    return preorder;
}
