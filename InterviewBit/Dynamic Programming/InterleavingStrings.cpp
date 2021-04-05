
int Solution::isInterleave(string A, string B, string C) {
	if (C.size() != (A.size() + B.size())) {
		return 0;
	}
	long long n = (long long)A.size();
	long long m = (long long)B.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 1;
	for (int j = 1; j <= m; j++) {
		if (C[j - 1] != B[j - 1]) {
			break;
		} else {
			dp[0][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (C[i - 1] != A[i - 1]) {
			break;
		} else {
			dp[i][0] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (C[i + j - 1] != A[i - 1] && C[i + j - 1] != B[j - 1]) {
				dp[i][j] = 0;
			} else if (C[i + j - 1] == A[i - 1] && C[i + j - 1] == B[j - 1]) {
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			} else if (C[i + j - 1] == A[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	return dp[n][m];
}