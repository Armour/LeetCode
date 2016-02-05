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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> S;
        TreeNode *cur = root;
        while (true) {
            if (cur) {
                S.push(cur);
                cur = cur->left;
            } else if (S.empty()) {
                break;
            } else {
                cur = S.top();
                S.pop();
                k--;
                if (k == 0) return cur->val;
                cur = cur->right;
            }
        }
        return NULL;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root->leftSum + 1 == k)
            return root->val;
        else if (root->leftSum + 1 > k)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - root->leftSum - 1);
    }
};

