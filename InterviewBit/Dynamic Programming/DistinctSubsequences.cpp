int f(string s, string t) {
	int n = s.size();
	int m = t.size();
	vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0LL));
	for (int j = 0; j <= n; j++) {
		dp[0][j] = 1LL;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] == t[i - 1]) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			} else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	return dp[m][n];
}
int Solution::numDistinct(string A, string B) {
	return f(A, B);
}
