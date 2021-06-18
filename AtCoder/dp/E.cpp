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
    int n, w;
    read(n, w);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        read(arr[i].first, arr[i].second);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n * 1005LL, -1));
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n * 1005LL; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = (long long)1e18;
            } else if (arr[i - 1].second <= j) {
                dp[i][j] = min(arr[i - 1].first + dp[i - 1][j - arr[i - 1].second], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n * 1005LL; ++j) {
        if (dp[n][j] <= w) ans = j;
    }
    write(ans, "\n");
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