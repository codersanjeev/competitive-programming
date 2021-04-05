class Solution {
   public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const long long MOD = 1e9 + 7, N = A.size();
        sort(A.begin(), A.end());
        long long ans = 0;
        unordered_map<long long, long long> dp;
        for (long long i = 0; i < N; i++) {
            dp[A[i]] = 1;
            for (long long j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    dp[A[i]] += dp[A[j]] * dp[A[i] / A[j]];
                    dp[A[i]] %= MOD;
                }
            }
            ans += dp[A[i]];
            ans %= MOD;
        }
        return ans;
    }
};