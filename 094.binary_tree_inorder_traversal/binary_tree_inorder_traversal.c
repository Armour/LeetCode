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
void traversal(struct TreeNode *node, int *inorder, int *counter) {
    if (node == NULL) return;
    traversal(node->left, inorder, counter);
    inorder[(*counter)++] = node->val;
    inorder = realloc(inorder, sizeof(int) * (*counter + 1));
    traversal(node->right, inorder, counter);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *inorder = malloc(sizeof(int));
    int counter = 0;
    traversal(root, inorder, &counter);
    *returnSize = counter;
    return inorder;
}
