class Solution {
   private:
    const int mod = 1e9 + 7;
    long dp[1001][1001];

   public:
    int kInversePairs(int n, int k) {
        int pos = (n * (n - 1)) >> 1;
        if (k < 0 || k > pos) return 0;
        if (k == 0 || k == pos) return 1;
        if (dp[n][k] != 0L) return dp[n][k];
        long ans = (long)kInversePairs(n, k - 1) +
                   (long)kInversePairs(n - 1, k) -
                   (long)kInversePairs(n - 1, k - n) + mod;
        return dp[n][k] = ans % mod;
    }
};