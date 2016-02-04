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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (root == NULL)
            return preorder;
        stack<TreeNode *> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode *tmp = S.top();
            preorder.push_back(tmp->val);
            S.pop();
            if (tmp->right != NULL)
                S.push(tmp->right);
            if (tmp->left != NULL)
                S.push(tmp->left);
        }
        return preorder;
    }
};
