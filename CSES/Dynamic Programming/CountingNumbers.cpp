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

int dp[20][20][20][20];

int solve(const string &s, int n, int x, bool leading, bool tight) {
    if (n == 0) return 1;
    if (dp[n][x][leading][tight] != -1) return dp[n][x][leading][tight];
    int ans = 0, ub = (tight ? s[s.size() - n] - '0' : 9);
    for (int digit = 0; digit <= ub; ++digit) {
        if (digit == x && leading == false) continue;
        ans += solve(s, n - 1, digit, leading and digit == 0, tight and digit == ub);
    }
    return dp[n][x][leading][tight] = ans;
}

void solve(int tc) {
    int a, b;
    read(a, b);
    string A = to_string(a - 1);
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    int x = solve(B, B.size(), 10, true, true);
    memset(dp, -1, sizeof(dp));
    int y = solve(A, A.size(), 10, true, true);
    write(x - y);
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