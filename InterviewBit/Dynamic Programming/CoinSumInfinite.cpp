const long long mod = 1000007;

int Solution::coinchange2(vector<int> &coins, int target) {
	long long n = (long long) coins.size();
	vector<long long> dp(target + 1, 0LL);
	dp[0] = 1LL;
	for (long long i = 0; i < n; i++) {
		for (int j = coins[i]; j <= target; j++) {
			dp[j] = (dp[j] % mod + dp[j - coins[i]] % mod) % mod;
		}
	}
	return dp[target] % mod;
}
