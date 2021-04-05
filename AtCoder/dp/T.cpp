#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    int N;
    string S;
    cin >> N >> S;
    // 4
    // <><
    // 5
    // dp[i][j] = number of ways to make permutation of length i + 1 with last element as j
    // j <= i + 1
    // j : [1, N]
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    vector<vector<int>> pre(N + 1, vector<int>(N + 1));
    // s[i] = '>' => dp[i][j] = sum(dp[i - 1][t]) for all t in [j, N]
    // s[i] = '<' => dp[i][j] = sum(dp[i - 1][t]) for all t in [1, j - 1]
    dp[1][1] = 1LL;
    pre[1][1] = 1LL;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (S[i - 2] == '>') {
                dp[i][j] = (pre[i - 1][i - 1] - pre[i - 1][j - 1] + mod) % mod;
            } else {
                dp[i][j] = pre[i - 1][j - 1];
            }
            pre[i][j] = (pre[i][j - 1] + dp[i][j]) % mod;
        }
    }
    int ans = 0LL;
    for (int j = 1; j <= N; j++) {
        ans = (ans + dp[N][j]) % mod;
    }
    cout << ans;
    return 0;
}