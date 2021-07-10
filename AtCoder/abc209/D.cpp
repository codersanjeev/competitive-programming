#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;
vector<int> adj[MAXN];
int depth[MAXN], up[MAXN][LOG];

void dfs(int u, int par) {
    for (const auto &v : adj[u]) {
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < LOG; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; --i) {
        if (k & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    int n, q, u, v;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    while (q--) {
        cin >> u >> v;
        int w = lca(u, v);
        if ((depth[u] + depth[v] - 2 * depth[w]) % 2 == 1) {
            cout << "Road\n";
        } else {
            cout << "Town\n";
        }
    }
    return 0;
}