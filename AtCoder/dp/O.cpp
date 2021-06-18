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

vector<vector<bool>> compatibility;

void solve(int tc) {
    int n, ele;
    read(n);
    compatibility = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            read(ele);
            if (ele == 1) compatibility[i][j] = true;
        }
    }
    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n) - 1; ++mask) {
        int a = __builtin_popcount(mask);
        for (int b = 0; b < n; ++b) {
            if (compatibility[a][b] && (mask & (1 << b)) == 0) {
                dp[mask ^ (1 << b)] = (dp[mask ^ (1 << b)] + dp[mask]) % MOD;
            }
        }
    }
    write(dp[(1 << n) - 1], "\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}