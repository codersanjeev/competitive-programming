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

void solve(int tc) {
    int n, m, a, b;
    read(n, m);
    vector<int> adj[n];
    while (m--) {
        read(a, b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> prev(n, -1);
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                prev[v] = u;
            }
        }
    }
    if (visited[n - 1]) {
        int curr = n - 1;
        vector<int> ans;
        while (prev[curr] != -1) {
            ans.push_back(curr + 1);
            curr = prev[curr];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        write(ans.size(), "\n");
        for (const auto &ele : ans) {
            write(ele, " ");
        }
    } else {
        write("IMPOSSIBLE");
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}
