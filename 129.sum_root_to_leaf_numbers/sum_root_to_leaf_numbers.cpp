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
    void sumUp(TreeNode *node, string val, int &res) {
        if (node->left == nullptr && node->right == nullptr) {
            res += stoi(val + to_string(node->val));
            return;
        }
        if (node->left != nullptr) sumUp(node->left, val + to_string(node->val), res);
        if (node->right != nullptr) sumUp(node->right, val + to_string(node->val), res);
    }

    int sumNumbers(TreeNode* root) {
        int res = 0;
        if (root == nullptr) return res;
        sumUp(root, "", res);
        return res;
    }
};
