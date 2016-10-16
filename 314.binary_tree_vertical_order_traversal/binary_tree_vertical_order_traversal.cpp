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
    vector<pair<int, int>> tmp_res;
    int min_depth = INT_MAX;
    int max_depth = INT_MIN;
        
    void search(TreeNode *node, int depth) {
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root != nullptr) {
            queue<pair<TreeNode *, int>> q;
            q.push(make_pair(root, 0));
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                min_depth = min(min_depth, p.second);
                max_depth = max(max_depth, p.second);
                tmp_res.push_back(make_pair(p.first->val, p.second));
                if (p.first->left != nullptr)
                    q.push(make_pair(p.first->left, p.second - 1));
                if (p.first->right != nullptr)
                    q.push(make_pair(p.first->right, p.second + 1));
            }
        }
            search(root, 0);
        for (int i = min_depth; i <= max_depth; i++) {
            vector<int> tmpv;
            res.push_back(tmpv);
        }
        for (auto p: tmp_res) {
            res[p.second - min_depth].push_back(p.first);
        }
        return res;
    }
};
