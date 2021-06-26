#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, a, b, c;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        b *= 2;
        c *= 2;
        if (a == 1) {
            arr[i] = make_pair(b, c);
        } else if (a == 2) {
            arr[i] = make_pair(b, c - 1);
        } else if (a == 3) {
            arr[i] = make_pair(b + 1, c);
        } else {
            arr[i] = make_pair(b + 1, c - 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (max(arr[i].first, arr[j].first) <=
                min(arr[i].second, arr[j].second)) {
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}