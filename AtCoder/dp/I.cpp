#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for (auto &ele : p) cin >> ele;
    int minHeads = (n + 1) / 2;
    vector<vector<double>> dp(n + 1, vector<double>(minHeads + 1, 0));
    for (int j = 0; j <= minHeads; ++j) dp[0][j] = 0;
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= minHeads; ++j) {
            dp[i][j] = dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1 - p[i - 1]);
        }
    }
    cout << fixed << setprecision(16) << dp[n][minHeads];
    return 0;
}