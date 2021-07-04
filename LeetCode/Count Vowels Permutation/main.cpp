class Solution {
   public:
    int countVowelPermutation(int n) {
        const long mod = 1e9 + 7;
        vector<vector<long>> dp(n, vector<long>(5, 1L));
        for (long i = 1; i < n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        long ans = 0L;
        for (const auto &ele : dp[n - 1]) {
            ans = (ans + ele) % mod;
        }
        return ans % mod;
    }
};