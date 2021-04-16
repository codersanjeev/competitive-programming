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

vector<vector<int>> dp;

int solve(int a, int b) {
    if (a == b) return 0;
    int ans = 1e18;
    if (dp[a][b] != -1) return dp[a][b];
    for (int k = 1; k < b; ++k) {
        ans = min(ans, 1 + solve(a, k) + solve(a, b - k));
    }
    for (int k = 1; k < a; ++k) {
        ans = min(ans, 1 + solve(k, b) + solve(a - k, b));
    }
    return dp[a][b] = ans;
}

void solve(int tc) {
    int a, b;
    read(a, b);
    dp = vector<vector<int>>(a + 1, vector<int>(b + 1, -1));
    int ans = solve(a, b);
    write(ans);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}