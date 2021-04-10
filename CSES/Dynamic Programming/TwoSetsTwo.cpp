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

int dp[501][63000];

int solve(int i, int x) {
    if (i == 0 && x == 0) {
        return 1;
    }
    if (i == 0) {
        return 0;
    }
    if (dp[i][x] != -1) {
        return dp[i][x];
    }
    int ans = solve(i - 1, x);
    if (x - i >= 0) {
        ans = (ans + solve(i - 1, x - i)) % MOD;
    }
    return dp[i][x] = ans;
}

void solve(int tc) {
    int n;
    read(n);
    int s = (n * (n + 1)) / 2;
    if (s % 2 != 0) {
        write("0\n");
    } else {
        memset(dp, -1, sizeof(dp));
        write((solve(n, s / 2) * 500000004) % MOD, "\n");
    }
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