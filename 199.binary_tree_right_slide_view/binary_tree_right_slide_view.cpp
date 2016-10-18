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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<pair<TreeNode *, int>> q;
        if (root != NULL)
            q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> cur = q.front();
            q.pop();
            if (res.size() <= cur.second) {
                res.push_back(0);
            }
            res[cur.second] = cur.first->val;
            if (cur.first->left != NULL)
                q.push(make_pair(cur.first->left, cur.second + 1));
            if (cur.first->right != NULL)
                q.push(make_pair(cur.first->right, cur.second + 1));
        }
        return res;
    }
};
