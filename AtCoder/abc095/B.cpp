#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007LL;

void solve() {
    int N, X, ans = 0;
    cin >> N >> X;
    vector<int> m(N);
    for (auto &ele : m) {
        cin >> ele;
    }
    sort(m.begin(), m.end());
    for (const auto &ele : m) {
        X -= ele;
        if (X < 0) {
            break;
        } else {
            ans++;
        }
    }
    if (X > 0) {
        ans += (X / m[0]);
    }
    cout << ans;
}

signed main() {
    int tc = 1LL;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}