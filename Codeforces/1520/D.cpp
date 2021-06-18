#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (auto &ele : arr) cin >> ele;
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            ans += mp[arr[i] - i];
            mp[arr[i] - i]++;
        }
        cout << ans << "\n";
    }
    return 0;
}