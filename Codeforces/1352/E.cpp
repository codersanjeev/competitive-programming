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
// #define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 8e3 + 5;
const int MAXHASH = 64e6 + 5;
vector<int> arr(MAX);
vector<int> pre(MAX);
vector<bool> mp(MAXHASH);

void solve() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        fill(mp.begin(), mp.end(), false);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pre[i] = arr[i];
        }
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == 0) {
                    // pre[j]
                    mp[arr[j]] = true;
                } else {
                    // pre[j] - pre[i - 1]
                    mp[arr[j] - arr[i - 1]] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (mp[pre[i]])
                ans++;
        cout << ans << "\n";
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
