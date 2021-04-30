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

vector<int> pref;
vector<vector<int>> dp;

int sum(int x, int y) {
    return pref[y] - (x > 0 ? pref[x - 1] : 0);
}

int solve(const vector<int> &arr, int i, int j) {
    if (i == j) return 0;
    int ans = 1e18;
    if (dp[i][j] != -1) return dp[i][j];
    for (int k = i; k < j; ++k) {
        ans = min(ans, solve(arr, i, k) + solve(arr, k + 1, j) + sum(i, j));
    }
    return dp[i][j] = ans;
}

void solve(int tc) {
    int n;
    read(n);
    vector<int> arr(n);
    readContainer(arr);
    pref = arr;
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 1; i < n; ++i) pref[i] += pref[i - 1];
    int ans = solve(arr, 0, n - 1);
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