#include <bits/stdc++.h>
using namespace std;

#define int long long
#define infinity 2e18

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ele : a) cin >> ele;
    vector<int> p = a;
    for (int i = 1; i < n; ++i) p[i] += p[i - 1];
    auto query = [&](int i, int j) -> int {
        return i == 0 ? p[j] : p[j] - p[i - 1];
    };
    vector<vector<int>> dp(n, vector<int>(n, infinity));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] += query(i, j);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}