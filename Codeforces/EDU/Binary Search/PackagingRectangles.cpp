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

bool f(int h, int w, int n, int mid) {
    return (((mid / w) * (mid / h)) >= n);
}

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    int lo = 0, hi = 1;
    while (f(h, w, n, hi) == false) hi <<= 1;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (f(h, w, n, mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi;
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
