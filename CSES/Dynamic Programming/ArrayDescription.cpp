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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0LL));
    if (arr[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1LL);
    } else {
        dp[0][arr[0]] = 1LL;
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        } else {
            int x = arr[i];
            for (int k : {x - 1, x, x + 1}) {
                if (k >= 1 && k <= m)
                    dp[i][x] = (dp[i][x] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int ans = 0LL;
    for (int j = 1; j <= m; j++)
        ans = (ans + dp[n - 1][j]) % MOD;
    cout << ans;
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