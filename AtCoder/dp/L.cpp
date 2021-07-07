#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ele : a) cin >> ele;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = a[i];
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}