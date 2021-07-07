#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

void dfs(vector<int> adj[], vector<bool> &visited, vector<vector<int>> &dp, int u) {
    visited[u] = true;
    dp[u][0] = dp[u][1] = 1;
    for (const auto &v : adj[u]) {
        if (visited[v]) continue;
        dfs(adj, visited, dp, v);
        dp[u][0] = (dp[u][0] * dp[v][1]) % mod;
        dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1]) % mod) % mod;
    }
}

signed main() {
    int n, u, v;
    cin >> n;
    vector<int> adj[n];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<bool> visited(n, false);
    dfs(adj, visited, dp, 0);
    cout << (dp[0][0] + dp[0][1]) % mod;
    return 0;
}