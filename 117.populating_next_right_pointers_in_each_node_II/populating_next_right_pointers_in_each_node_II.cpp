/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                TreeLinkNode *next_node = root->next;
                while (next_node != nullptr) {
                    if (next_node->left) {
                        root->left->next = next_node->left;
                        break;
                    } else if (next_node->right) {
                        root->left->next = next_node->right;
                        break;
                    }
                    next_node = next_node->next;
                }
            }
        }
        if (root->right) {
            TreeLinkNode *next_node = root->next;
            while (next_node != nullptr) {
                if (next_node->left) {
                    root->right->next = next_node->left;
                    break;
                } else if (next_node->right) {
                    root->right->next = next_node->right;
                    break;
                }
                next_node = next_node->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};
