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
    int getMaxSum(TreeNode *node, int &res) {
        if (node == nullptr) return 0;
        int max_sum = node->val;
        int left = getMaxSum(node->left, res);
        int right = getMaxSum(node->right, res);
        int cur_max = max_sum + (left > 0) * left + (right > 0) * right;
        res = max(res, cur_max);
        return max(max(left, right), 0) + max_sum;
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        getMaxSum(root, res);
        return res;
    }
};
