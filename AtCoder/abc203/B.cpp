#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int temp = (100 * i) + j;
            ans += temp;
        }
    }
    cout << ans;
    return 0;
}