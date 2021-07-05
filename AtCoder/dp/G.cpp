#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int dfs(vector<int> adj[], int u) {
    int ans = 0;
    if (dp[u] != -1) return dp[u];
    for (const auto &v : adj[u]) {
        ans = max(ans, 1 + dfs(adj, v));
    }
    return dp[u] = ans;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    int ans = 0;
    dp.resize(n, -1);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(adj, i));
    }
    cout << ans;
    return 0;
}