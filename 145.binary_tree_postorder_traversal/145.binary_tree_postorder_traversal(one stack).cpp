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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vals;
        if(root == NULL)
            return vals;
        vector<TreeNode *> nodes;
        TreeNode *pre = NULL;
        nodes.push_back(root);
        while(!nodes.empty()) {
            TreeNode *p = nodes.back();
            if((p->left == NULL && p->right == NULL) ||
                (pre != NULL && (pre == p->left || pre == p->right))) {
                vals.push_back(p->val);
                nodes.pop_back();
                pre = p;
            } else {
                if(p->right != NULL)
                    nodes.push_back(p->right);
                if(p->left != NULL)
                    nodes.push_back(p->left);
            }
        }
        return vals;
    }
};
