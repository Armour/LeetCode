/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *buildTree(int* nums, int st, int ed) {
    if (st > ed) return NULL;
    int mid = (st + ed) / 2;
    struct TreeNode *p = malloc(sizeof(struct TreeNode));
    p->val = nums[mid];
    p->left = buildTree(nums, st, mid - 1);
    p->right = buildTree(nums, mid + 1, ed);
    return p;
}

struct TreeNode *sortedArrayToBST(int* nums, int numsSize) {
    return buildTree(nums, 0, numsSize - 1);
}

