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

void solve(int tc) {
    int n, k;
    read(n, k);
    vector<int> a(n);
    readContainer(a);
    // dp[i][j] = number of ways to distribute j candies to [0, i] children
    // answer = dp[n - 1][k]
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int j = 0; j <= k; j++) {
        dp[0][j] = j <= a[0] ? 1 : 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int ans = 0;
            ans = (ans + (j - 1 >= 0 ? dp[i][j - 1] : 0)) % MOD;
            ans = (ans + dp[i - 1][j]) % MOD;
            ans = (ans - (j - 1 - a[i] >= 0 ? dp[i - 1][j - 1 - a[i]] : 0) + MOD) % MOD;
            dp[i][j] = ans;
        }
    }
    write(dp[n - 1][k], "\n");
}

signed main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}