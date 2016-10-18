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
    unordered_map<int, int> m;
    int cnt = 0;
    
    TreeNode *construct(int left, int right, vector<int> &preorder) {
        if (left > right) return nullptr;
        TreeNode *node = new TreeNode(preorder[cnt++]);
        node->left = construct(left, m[node->val] - 1, preorder);
        node->right = construct(m[node->val] + 1, right, preorder);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return construct(0, inorder.size() - 1, preorder);
    }
};
