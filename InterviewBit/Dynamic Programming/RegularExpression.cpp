int f(string s, string p) {
	int n = s.size();
	int m = p.size();
	if (m == 0) {
		return (n == 0);
	}
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;
	for (int j = 1; j <= m; j++) {
		if (p[j - 1] == '*') {
			dp[0][j] = dp[0][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			} else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[n][m];
}

int Solution::isMatch(const string A, const string B) {
	return f(A, B);
}