/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n < k) {
            cout << "NO\n";
        } else if ((n - k + 1) > 0 && (n - k + 1) % 2 == 1) {
            cout << "YES\n";
            cout << n - k + 1 << " ";
            k--;
            while (k--)
                cout << "1 ";
            cout << "\n";
        } else if (n - 2 * (k - 1) > 0 && (n - 2 * (k - 1)) % 2 == 0) {
            cout << "YES\n";
            cout << n - 2 * (k - 1) << " ";
            k--;
            while (k--)
                cout << "2 ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
