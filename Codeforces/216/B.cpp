#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

// C(n, r) = n! / (r! * (n - r)!)
// C(n, r) = C(n, n - r)
// C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
int nCr(int n, int r) {
    long double res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return (int)(res + 0.01);
}

// (x ^ y) % mod
int modpow(int x, int y, int m) {
    x %= m;
    int res = 1LL;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int cc = 0;
vector<int> comp;

void dfs(vector<int> adj[], vector<bool> &visited, int u, int color) {
    if (visited[u] == true && comp[u] != color) {
        cc++;
        return;
    }
    if (visited[u] == true) {
        return;
    }
    visited[u] = true;
    comp[u] = color;
    for (const auto &v : adj[u]) {
        dfs(adj, visited, v, color ^ 1);
    }
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    vector<bool> visited(n, false);
    comp.resize(n, -1);
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            cc = 0;
            dfs(adj, visited, i, 0);
            ans += cc / 2;
        }
    }
    int rem = n - ans;
    cout << ans + (rem % 2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}