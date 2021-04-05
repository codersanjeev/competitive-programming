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

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// taken: plates taken from 0 to index - 1 plates
int solve(vector<vector<int>> &plates, vector<vector<int>> &dp, int n, int k, int p, int index, int taken) {
    if (taken == p) {
        return 0;
    }
    if (index > n || taken > p) {
        return -1e9;
    }
    int ans = -1e9;
    if (dp[index][taken] != ans) {
        return dp[index][taken];
    }
    for (int i = 0; i <= k; i++) {
        ans = max(ans, plates[index][i] + solve(plates, dp, n, k, p, index + 1, taken + i));
    }
    return dp[index][taken] = ans;
}

void solve(int tc) {
    int N, K, P;
    read(N, K, P);
    vector<vector<int>> plates(N + 1, vector<int>(K + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>((K * N) + 1, -1e9));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            read(plates[i][j]);
            plates[i][j] += plates[i][j - 1];
        }
    }
    int ans = solve(plates, dp, N, K, P, 1, 0);
    write("Case #", tc, ": ", ans, "\n");
}

signed main() {
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) {
        solve(curr);
    }
    return 0;
}