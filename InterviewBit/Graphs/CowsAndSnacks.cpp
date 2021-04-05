const int N = 1e5 + 1;
vector<int> adj[N];

void dfs(int u, vector<bool> &visited) {
    visited[u] = true;
    for(const auto &v : adj[u]) {
        if(!visited[v]) {
            dfs(v, visited);
        }
    }
}

int Solution::solve(int n, vector<vector<int>> &B) {
    for(auto &ele : adj) {
        ele.clear();
    }
    vector<bool> visited(n, false);
    int m = B.size();
    for(int i = 0; i < m; i++) {
        int x = B[i][0] - 1;
        int y = B[i][1] - 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int connected = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, visited);
            connected++;
        }
    }
    return m - n + connected;
}
