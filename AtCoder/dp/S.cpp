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

int dp[10001][101][2];

int solve(string &s, int D, int pos, int d, bool c) {
    int ub = c ? s[pos] - '0' : 9;
    if (dp[pos][d][c] != -1) return dp[pos][d][c];
    int ans = 0;
    if (pos == s.size() - 1) {
        for (int x = 0; x <= ub; ++x) {
            if (x % D == d) {
                ans = (ans + 1) % MOD;
            }
        }
    } else {
        for (int x = 0; x <= ub; ++x) {
            ans = (ans + solve(s, D, pos + 1, (D + d - x % D) % D, c && x == ub)) % MOD;
        }
    }
    return dp[pos][d][c] = ans;
}

void solve(int tc) {
    string k;
    int d;
    read(k, d);
    memset(dp, -1, sizeof(dp));
    int ans = (solve(k, d, 0, 0, true) - 1 + MOD) % MOD;
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