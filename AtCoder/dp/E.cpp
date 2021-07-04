#include <bits/stdc++.h>
using namespace std;

#define int long long
#define infinity 0x3f3f3f3f

signed main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    int maxValue = *max_element(cbegin(v), cend(v));
    maxValue *= n;
    vector<vector<int>> dp(n, vector<int>(maxValue + 1, infinity));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }
    dp[0][v[0]] = w[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= maxValue; ++j) {
            if (v[i] <= j) {
                dp[i][j] = min(dp[i - 1][j], w[i] + dp[i - 1][j - v[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int j = maxValue; j >= 0; --j) {
        if (dp[n - 1][j] <= W) {
            cout << j;
            break;
        }
    }
    return 0;
}