bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &recstack, int u) {
    if (visited[u] == true) {
        return false;
    }
    visited[u] = true;
    recstack[u] = true;
    for (const auto &v : adj[u]) {
        if ((visited[v] == false && dfs(adj, visited, recstack, v)) || recstack[v]) {
            return true;
        }
    }
    recstack[u] = false;
    return false;
}

int Solution::solve(int nodes, vector<vector<int>> &edges) {
    vector<int> adj[nodes];
    vector<bool> visited(nodes, false);
    vector<bool> recstack(nodes, false);
    for (const auto &edge : edges) {
        adj[edge[0] - 1].push_back(edge[1] - 1);
    }
    for (int i = 0; i < nodes; i++) {
        if (visited[i] == false) {
            if (dfs(adj, visited, recstack, i)) {
                return 1;
            }
        }
    }
    return 0;
}
