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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!node) return NULL;
        tab.clear();
        dfs(node);
        return tab[node];
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> tab;
    
    void dfs(UndirectedGraphNode *node) {
        if (tab.find(node) != tab.end()) return;
        
        vector<UndirectedGraphNode *> &arr = node->neighbors;
        UndirectedGraphNode *mirror_node = new UndirectedGraphNode(node->label);
        tab[node] = mirror_node;
        for (int i=0; i<arr.size(); ++i) {
            dfs(arr[i]);
            mirror_node->neighbors.push_back(tab[arr[i]]);
        }
    }
};

