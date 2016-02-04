/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkSymmetric(struct TreeNode *leftNode, struct TreeNode *rightNode) {
    if (leftNode == NULL && rightNode == NULL)
        return true;
    if (leftNode == NULL || rightNode == NULL)
        return false;
    return leftNode->val == rightNode->val
            && checkSymmetric(leftNode->left, rightNode->right)
            && checkSymmetric(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode *root) {
    if (root == NULL) return true;
    return checkSymmetric(root->left, root->right);
}
