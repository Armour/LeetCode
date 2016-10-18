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
    
    TreeNode *construct(int left, int right, vector<int> &postorder) {
        if (left > right) return nullptr;
        TreeNode *node = new TreeNode(postorder[cnt--]);
        node->right = construct(m[node->val] + 1, right, postorder);
        node->left = construct(left, m[node->val] - 1, postorder);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        cnt = postorder.size() - 1;
        return construct(0, inorder.size() - 1, postorder);
    }
};
