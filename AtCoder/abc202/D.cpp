#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int a, b, k;
    cin >> a >> b >> k;
    int dp[61][61];
    dp[0][0] = 1;
    for (int i = 1; i < 61; ++i) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    int n = a + b;
    for (int i = 0; i < n; ++i) {
        int cnt = dp[a + b - 1][b];
        if (cnt >= k) {
            cout << 'a';
            a--;
        } else {
            cout << 'b';
            k -= cnt;
            b--;
        }
    }
    return 0;
}