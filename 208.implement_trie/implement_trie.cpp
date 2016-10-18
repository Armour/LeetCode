class TrieNode {
public:
    char val;
    bool end;
    vector<TrieNode *> next;
    
    // Initialize your data structure here.
    TrieNode() {
        TrieNode('0');
    }
    
    TrieNode(char c) {
        val = c;
        end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) {
            int flag = false;
            for (int j = 0; j < node->next.size(); j++) {
                if (node->next[j]->val == word[i]) {
                    flag = true;
                    node = node->next[j];
                    break;
                }
            }
            if (!flag) {
                TrieNode *tmp_node = new TrieNode(word[i]);
                node->next.push_back(tmp_node);
                node = tmp_node;
            }
            if (i == word.length() - 1) {
                node->end = true;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) {
            int flag = false;
            for (int j = 0; j < node->next.size(); j++) {
                if (node->next[j]->val == word[i]) {
                    flag = true;
                    node = node->next[j];
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return node->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int flag = false;
            for (int j = 0; j < node->next.size(); j++) {
                if (node->next[j]->val == prefix[i]) {
                    flag = true;
                    node = node->next[j];
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
