#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        int dp[N + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++) {
            int zeros = 0, ones = 0;
            for (const auto& ele : strs[i - 1]) {
                if (ele == '0') {
                    zeros += 1;
                } else {
                    ones += 1;
                }
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - zeros][k - ones]);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[N][m][n];
    }
};