bool dfs(vector<int> adj[], vector<bool> &visited, int u, int p) {
    visited[u] = true;
    for (const auto &v : adj[u]) {
        if (visited[v] == false) {
            if (dfs(adj, visited, v, u)) {
                return true;
            }
        } else if (v != p) {
            return true;
        }
    }
    return false;
}

int Solution::solve(int nodes, vector<vector<int>> &edges) {
    vector<int> adj[nodes];
    vector<bool> visited(nodes, false);
    for (const auto &edge : edges) {
        adj[edge[0] - 1].push_back(edge[1] - 1);
        adj[edge[1] - 1].push_back(edge[0] - 1);
    }
    for (int i = 0; i < nodes; i++) {
        if (visited[i] == false && dfs(adj, visited, i, -1)) {
            return 1;
        }
    }
    return 0;
}
