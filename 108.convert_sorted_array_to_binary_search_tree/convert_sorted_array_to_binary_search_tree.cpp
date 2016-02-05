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
    TreeNode *buildTree(vector<int> &nums, int st, int ed) {
        if (st > ed) return NULL;
        int mid = (st + ed) / 2;
        TreeNode *p = new TreeNode(nums[mid]);
        p->left = buildTree(nums, st, mid - 1);
        p->right = buildTree(nums, mid + 1, ed);
        return p;
    }

    TreeNode *sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
