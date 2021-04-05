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

bool f(long double x, vector<long double> &arr, int k) {
    int sum = 0;
    for (const auto &ele : arr)
        sum += (int)(ele / x);
    return sum >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long double> arr(n);
    for (auto &ele : arr)
        cin >> ele;
    long double lo = 0.0, hi = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < 100; i++) {
        long double mid = lo + (hi - lo) / 2.0;
        if (f(mid, arr, (int)k)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(6) << (long double)lo;
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
