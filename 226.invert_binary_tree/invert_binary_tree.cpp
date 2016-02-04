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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) return root;
        TreeNode *leftNode = invertTree(root->left);
        TreeNode *rightNode = invertTree(root->right);
        root->left = rightNode;
        root->right = leftNode;
        return root;
    }
};
