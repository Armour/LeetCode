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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        if (root == NULL) return res;
        queue< pair<TreeNode*, int> > Q;
        Q.push(make_pair(root, 0));
        while (!Q.empty()) {
            pair<TreeNode*, int> p = Q.front();
            Q.pop();
            TreeNode *node = p.first;
            if (p.second + 1 > res.size()) {
                vector<int> tmp;
                tmp.push_back(node->val);
                res.push_back(tmp);
            } else {
                res[p.second].push_back(node->val);
            }
            if (node->left != NULL)
                Q.push(make_pair(node->left, p.second + 1));
            if (node->right != NULL)
                Q.push(make_pair(node->right, p.second + 1));
        }
        return res;
    }
};
