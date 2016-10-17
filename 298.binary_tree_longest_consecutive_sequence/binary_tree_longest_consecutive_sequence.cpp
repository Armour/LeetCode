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
    int res = 0;
    
    int search(TreeNode *node) {
        int val = 1;
        if (node->left) {
            int left = search(node->left);
            if (node->left->val == node->val + 1) {
                val = max(val, left + 1);
            }
        }
        if (node->right) {
            int right = search(node->right);
            if (node->right->val == node->val + 1) {
                val = max(val, right + 1);
            }
        }
        res = max(res, val);
        return val;
    }
    
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else {
            search(root);
        }
        return res;
    }
};
