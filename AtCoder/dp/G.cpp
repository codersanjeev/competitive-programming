#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int u) {
    visited[u] = true;
    ans[u] = 0;
    for (const auto &v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, ans, v);
        }
        ans[u] = max(ans[u], 1 + ans[v]);
    }
}

void solve(int tc) {
    int n, m, x, y;
    read(n, m);
    vector<int> adj[n];
    while (m--) {
        read(x, y);
        x--;
        y--;
        adj[x].push_back(y);
    }
    vector<bool> visited(n, false);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, ans, i);
        }
    }
    write(*max_element(ans.begin(), ans.end()));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}