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
    int getHeight(TreeNode *node) {
        if (node == NULL) return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return (leftHeight > rightHeight? leftHeight: rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int depth = getHeight(root);
        if (depth == -1)
            return false;
        else
            return true;
    }
};
