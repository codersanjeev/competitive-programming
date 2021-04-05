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

long double f(long double x) {
    return (x * x) + sqrt(x);
}

void solve() {
    // x ^ x + sqrt(x) = c
    long double c;
    cin >> c;
    long double lo = (long double)0;
    long double hi = (long double)120000;
    for (int i = 0; i < 100; i++) {
        long double mid = lo + (hi - lo) / (long double)2;
        if (f(mid) <= c)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(15) << lo;
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
