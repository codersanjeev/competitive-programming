#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int j = 0; j <= W; ++j) {
        dp[0][j] = (j >= w[0] ? v[0] : 0);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (w[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 1][W];
    return 0;
}