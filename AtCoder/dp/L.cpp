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

int solve(const vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = arr[i];
    return dp[i][j] = max(arr[i] - solve(arr, i + 1, j, dp), arr[j] - solve(arr, i, j - 1, dp));
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solve(arr, 0, n - 1, dp);
    write(ans, "\n");
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