/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int cnt;
    vector<TreeNode *>v;

    void inorder(TreeNode *node) {
        if (node == nullptr) return;
        inorder(node->left);
        v.push_back(node);
        inorder(node->right);
    }

    BSTIterator(TreeNode *root) {
        inorder(root);
        cnt = -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cnt + 1 < v.size();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext())
            return v[++cnt]->val;
        else
            return 0;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
