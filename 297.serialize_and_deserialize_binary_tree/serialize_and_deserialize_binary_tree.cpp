/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        deque<string> q;
        queue<TreeNode *> bfs;
        if (root == nullptr) {
            return res + "]";
        } else if (root->left == nullptr && root->right == nullptr) {
            return res + to_string(root->val) + "]";
        }
        bfs.push(root);
        while (!bfs.empty()) {
            TreeNode *node = bfs.front();
            bfs.pop();
            if (node != nullptr) {
                q.push_back(to_string(node->val));
                bfs.push(node->left);
                bfs.push(node->right);
            } else {
                q.push_back("null");
            }
        }
        while (q.back().compare("null") == 0) q.pop_back();
        for (auto i = q.begin(); i != q.end(); i++) {
            if (i != q.begin()) {
                res += "," + *i;
            } else {
                res += *i;
            }
        }
        return res + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.length() - 2);
        vector<string> v;
        istringstream ss(data);
        string str;
        while (getline(ss, str, ',')) {
            v.push_back(str);
        }
        if (v.size() == 0 || v[0].compare("null") == 0) return nullptr;
        TreeNode *tmp = new TreeNode(stoi(v[0]));
        TreeNode *res = tmp;
        int cnt = 1;
        queue<TreeNode *> bfs;
        bfs.push(tmp);
        while (!bfs.empty()) {
            TreeNode *node = bfs.front();
            bfs.pop();
            if (cnt <= v.size() - 1) {
                if (v[cnt].compare("null") != 0) {
                    TreeNode *tmp = new TreeNode(stoi(v[cnt]));
                    node->left = tmp;
                    bfs.push(tmp);
                }
                cnt++;
            }            
            if (cnt <= v.size() - 1) {
                if (v[cnt].compare("null") != 0) {
                    TreeNode *tmp = new TreeNode(stoi(v[cnt]));
                    node->right = tmp;
                    bfs.push(tmp);
                }
                cnt++;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
