/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        if (m.find(node) == m.end()) {
            m[node] = new UndirectedGraphNode(node->label);
            for (int i = 0; i < node->neighbors.size(); i++) {
                m[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return m[node];
    }
};
