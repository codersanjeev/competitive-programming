#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (auto &ele : a) cin >> ele;
    vector<vector<int>> dp(n, vector<int>(K + 1, 0));
    for (int j = 0; j <= K; ++j) dp[0][j] = (j <= a[0] ? 1 : 0);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            if (j - 1 - a[i] >= 0) dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - a[i]] + mod) % mod;
        }
    }
    cout << dp[n - 1][K];
    return 0;
}