#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

void solve() {
    int n, q, ele;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--) {
        cin >> ele;
        int lo = 0, hi = n - 1;
        bool ok = false;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == ele) {
                ok = true;
                break;
            } else if (arr[mid] < ele) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
