#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> happiness(n);
    for (int i = 0; i < n; ++i) {
        vector<int> curr(3);
        for (int j = 0; j < 3; ++j) cin >> curr[j];
        happiness[i] = curr;
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int j = 0; j < 3; ++j) dp[0][j] = happiness[0][j];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = happiness[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = happiness[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = happiness[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = *max_element(cbegin(dp[n - 1]), cend(dp[n - 1]));
    cout << ans;
    return 0;
}