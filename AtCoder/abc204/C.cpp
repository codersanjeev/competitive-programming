#include <bits/stdc++.h>
using namespace std;

int reach = 0;

void dfs(vector<int> adj[], vector<bool> &visited, int u) {
    if (visited[u]) return;
    visited[u] = true;
    ++reach;
    for (const auto &v : adj[u]) {
        dfs(adj, visited, v);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        reach = 0;
        dfs(adj, visited, i);
        ans += reach;
    }
    cout << ans;
    return 0;
}