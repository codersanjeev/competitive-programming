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
#define int long long
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
    int n;
    read(n);
    vector<int> dp(n + 1);
    if(n == 1) {
        write(1, "\n");
    } else if(n == 2) {
        write(2, "\n");
    } else if(n == 3) {
        write(4, "\n");
    } else if(n == 4) {
        write(8, "\n");
    } else if(n == 5) {
        write(16, "\n");
    } else if(n == 6) {
        write(32, "\n");
    } else {
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        dp[4] = 8;
        dp[5] = 16;
        dp[6] = 32;
        for(int i = 7; i <= n; i++) {
            dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod + dp[i - 4] % mod + dp[i - 5] % mod + dp[i - 6] % mod) % mod;
        }
        write(dp[n]);
    }
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
