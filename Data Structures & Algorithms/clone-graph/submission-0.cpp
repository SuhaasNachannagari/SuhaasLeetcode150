/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<Node*, Node*> oldToNew;
    oldToNew[node] = new Node(node->val);
    dfs(node, oldToNew);
    return oldToNew[node];
}

void dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
    for (Node* neighbor : node->neighbors) {
        if (oldToNew.find(neighbor) == oldToNew.end()) {
            oldToNew[neighbor] = new Node(neighbor->val);
            dfs(neighbor, oldToNew);
        }
        oldToNew[node]->neighbors.push_back(oldToNew[neighbor]);
    }
}
};
