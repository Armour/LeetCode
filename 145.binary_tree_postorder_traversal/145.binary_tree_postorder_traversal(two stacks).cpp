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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> S;
        stack<int> Res;
        vector<int> postorder;
        if (root == NULL)
            return postorder;
        S.push(root);
        while (!S.empty()) {
            TreeNode *tmp = S.top();
            Res.push(tmp->val);
            S.pop();
            if (tmp->left != NULL)
                S.push(tmp->left);
            if (tmp->right != NULL)
                S.push(tmp->right);
        }
        while (!Res.empty()) {
            postorder.push_back(Res.top());
            Res.pop();
        }
        return postorder;
    }
};
