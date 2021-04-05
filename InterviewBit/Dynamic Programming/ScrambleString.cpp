int Solution::isScramble(const string str1, const string str2) {
	int n = str1.size();
	if (n == 0) {
		return true;
	} else if (n == 1) {
		return str1 == str2;
	}
	bool dp[n + 1][n][n];
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++) {
			dp[1][i][j] = (str1[i] == str2[j]);
		}
	for (int len = 2 ; len <= n ; len++) {
		for (int i = 0 ; i <= n - len ; i++) {
			for (int j = 0 ; j <= n - len ; j++) {
				dp[len][i][j] = false;
				for (int k = 1 ; k < len && dp[len][i][j] == false ; k++) {
					dp[len][i][j] = dp[len][i][j] || ( dp[k][i][j] && dp[len - k][i + k][j + k] );
					dp[len][i][j] = dp[len][i][j] || ( dp[k][i][j + len - k] && dp[len - k][i + k][j] );
				}
			}
		}
	}
	return dp[n][0][0];
}
