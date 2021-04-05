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

bool dfs(vector<int> adj[], vector<bool> &visited, vector<int> &colors, int u, int color, int parent) {
    visited[u] = true;
    colors[u] = color;
    for (const auto &v : adj[u]) {
        if (v == parent) {
            continue;
        }
        if (visited[v] == false) {
            int x = (color == 1 ? 2 : 1);
            if (dfs(adj, visited, colors, v, x, u) == false) {
                return false;
            }
        }
        if (colors[v] == colors[u]) {
            return false;
        }
    }
    return true;
}

void solve(int tc) {
    int n, m, u, v;
    read(n, m);
    vector<int> adj[n];
    while (m--) {
        read(u, v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colors(n);
    vector<bool> visited(n, false);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            ok = ok & dfs(adj, visited, colors, i, 1, -1);
        }
    }
    if (ok) {
        for (const auto &ele : colors) {
            write(ele, " ");
        }
    } else {
        write("IMPOSSIBLE");
    }
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