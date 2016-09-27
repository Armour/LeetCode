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
    int findL(TreeNode *node, vector<vector<int>> &res) {
        if (!node) return 0;
        if (!node->left && !node->right) {
            if (res.size() <= 0) {
                vector<int> v;
                res.push_back(v);
            }
            res[0].push_back(node->val);
            return 0;
        }
        int right = findL(node->right, res);
        int left = findL(node->left, res);
        int depth = max(left, right) + 1;
        if (res.size() <= depth) {
            vector<int> v;
            res.push_back(v);
        }
        res[depth].push_back(node->val);
        return depth;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        findL(root, res);
        return res;
    }
};
