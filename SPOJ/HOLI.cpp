#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

// template <class T>
// using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template <typename... T>
// void read(T &...args) {
//     ((cin >> args), ...);
// }

// template <typename... T>
// void write(T &&...args) {
//     ((cout << args), ...);
// }

// template <typename T>
// void readContainer(T &t) {
//     for (auto &e : t) {
//         read(e);
//     }
// }

// template <typename T>
// void writeContainer(T &t) {
//     for (const auto &e : t) {
//         write(e, " ");
//     }
//     write("\n");
// }

int ans = 0;

/**
 * returns the count from a particular node @u
 */
int dfs(vector<pair<int, int>> adj[], vector<bool> &visited, vector<int> &count, int u) {
    visited[u] = true;
    count[u] = 1;
    for (const auto &ele : adj[u]) {
        int v = ele.first, wt = ele.second;
        if (visited[v] == false) {
            int x = dfs(adj, visited, count, v);
            ans += 2 * wt * min(x, ((int)count.size() - x));
            count[u] += x;
        }
    }
    return count[u];
}

void solve(int tc) {
    int n, x, y, z;
    cin >> n;
    vector<pair<int, int>> adj[n];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
        --x;
        --y;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    vector<bool> visited(n, false);
    vector<int> count(n, 0);
    ans = 0;
    dfs(adj, visited, count, 0);
    cout << "Case #" << tc << ": " << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}