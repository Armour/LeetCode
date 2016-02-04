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
void traversal(struct TreeNode *node, int *postorder, int *counter) {
    if (node == NULL) return;
    traversal(node->left, postorder, counter);
    traversal(node->right, postorder, counter);
    postorder[(*counter)++] = node->val;
    postorder = realloc(postorder, sizeof(int) * (*counter + 1));
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *postorder = malloc(sizeof(int));
    int counter = 0;
    traversal(root, postorder, &counter);
    *returnSize = counter;
    return postorder;
}
