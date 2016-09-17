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
    bool validation(TreeNode *root, long lower, long upper) {
        if (root == NULL) return true;
        bool left = validation(root->left, lower, root->val);
        bool right = validation(root->right, root->val, upper);
        if (!left || !right) return false;
        return root->val < upper && root->val > lower;
    }

    bool isValidBST(TreeNode* root) {
        return validation(root, LONG_MIN, LONG_MAX);
    }
};
