#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t, n, ele;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> ele;
            ans += (n - i) * mp[ele];
            mp[ele] += (i + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}