/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
// #define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class... Args>
auto create(size_t n, Args&&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
    ((cout << args), ...);
}

void solve() {
    int n, x;
    read(n, x);
    vector<int> page(n), cost(n);
    for(int i = 0; i < n; i++)
        read(cost[i]);
    for(int i = 0; i < n; i++)
        read(page[i]);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - cost[i - 1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i - 1]] + page[i - 1]);
            }
        }
    }
    write(dp[n][x], "\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    solve();
    return 0;
}
