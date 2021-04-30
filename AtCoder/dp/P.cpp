#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

const int N = 1e5;
vector<int> adj[N];
vector<vector<int>> dp(N, vector<int>(2, 0));

void dfs(int u, int par) {
    dp[u][0] = dp[u][1] = 1;
    for (const auto &v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % MOD) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

void solve(int tc) {
    int n, u, v;
    read(n);
    for (int i = 1; i < n; ++i) {
        read(u, v);
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    write((dp[0][0] + dp[0][1]) % MOD, "\n");
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}