int Solution::maxProfit(const vector<int> &prices) {
	int n = prices.size();
	if (n < 2) {
		return 0;
	}
	vector<vector<int>> dp(3, vector<int>(n, 0));
	for (int i = 1; i < 3; i++) {
		int mx = INT_MIN;
		for (int j = 1; j < n; j++) {
			mx = max(mx, dp[i - 1][j - 1] - prices[j - 1]);
			dp[i][j] = max(dp[i][j - 1], mx + prices[j]);
		}
	}
	return dp[2][n - 1];
}
