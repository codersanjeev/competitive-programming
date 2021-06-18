#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
vector<int> adj[N];
vector<bool> visited(N, false);
int nodes = 0;

void dfs(int u) {
    visited[u] = true;
    nodes++;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    visited.assign(N, false);
    for (auto &ele : adj)
        ele.clear();
    int n, m, cl, cr, x, y;
    cin >> n >> m >> cl >> cr;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            nodes = 0;
            dfs(i);
            if (cl <= cr) {
                ans += (cl * nodes);
            } else {
                ans += cl;
                ans += (cr * (nodes - 1));
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
