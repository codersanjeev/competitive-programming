int Solution::minPathSum(vector<vector<int>> &board) {
	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[0][0] = board[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = board[i][0] + dp[i - 1][0];
	}
	for (int j = 1; j < m; j++) {
		dp[0][j] = board[0][j] + dp[0][j - 1];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = board[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n - 1][m - 1];
}
