#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &ele : c) cin >> ele;
    sort(begin(c), end(c));
    int ans = 1LL;
    for (int i = 0; i < n; ++i) {
        ans = (ans * max(0LL, c[i] - i)) % mod;
    }
    cout << ans;
    return 0;
}