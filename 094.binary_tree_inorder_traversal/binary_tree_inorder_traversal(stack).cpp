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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == NULL)
            return inorder;
        stack<TreeNode *> S;
        TreeNode *current = root;
        while (true) {
            if (current != NULL) {
                S.push(current);
                current = current->left;
            } else if (S.empty()) {
                break;
            } else{
                current = S.top();
                S.pop();
                inorder.push_back(current->val);
                current = current->right;
            }
        }
        return inorder;
    }
};
