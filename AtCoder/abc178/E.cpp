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
    int n, x, y;
    cin >> n;
    vector<int> sum(n), diff(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        sum[i] = x + y;
        diff[i] = x - y;
    }
    int maxone = INT_MIN, maxtwo = INT_MIN;
    int minone = INT_MAX, mintwo = INT_MAX;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxone = max(maxone, sum[i]);
        maxtwo = max(maxtwo, diff[i]);
        minone = min(minone, sum[i]);
        mintwo = min(mintwo, diff[i]);
        ans = max({ans, maxone - minone, maxtwo - mintwo});
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
