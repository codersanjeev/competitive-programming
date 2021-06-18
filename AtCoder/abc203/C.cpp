#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k, ai, bi;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    int ans = 1;
    for (const auto &ele : arr) {
        if (k == 0) break;
        --k;
        if (ans == ele.first) {
            k += ele.second;
        }
        ++ans;
    }
    ans += k;
    cout << ans;
    return 0;
}