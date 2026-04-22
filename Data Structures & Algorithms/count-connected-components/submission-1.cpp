class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visited;
        int components = 0;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int node = 0; node < n; node++) {
            if (!(visited.count(node) > 0)) {
                dfs(node, adj, visited);
                components++;
            }
        }

        return components;
    }

    void dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(node) > 0) {
            return;
        }
        
        if (adj[node].empty()) {
            return;
        }

        visited.insert(node);

        for (const auto& nei : adj[node]) {
            dfs(nei, adj, visited);
        }

    }
};
