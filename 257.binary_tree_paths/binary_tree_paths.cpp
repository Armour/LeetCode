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
    string build(vector<int> &path) {
        string str;
        if (path.size() == 0) return str;
        str += to_string(path[0]);
        for (int i = 1; i < path.size(); i++) {
            str += "->" + to_string(path[i]);
        }
        return str;
    }

    void binaryTreePath(TreeNode *node, vector<string> &res, vector<int> &path) {
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            res.push_back(build(path));
        }
        if (node->left != NULL) binaryTreePath(node->left, res, path);
        if (node->right != NULL) binaryTreePath(node->right, res, path);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == NULL) return res;
        binaryTreePath(root, res, path);
        return res;
    }
};
