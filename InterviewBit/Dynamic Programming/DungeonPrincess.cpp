int Solution::calculateMinimumHP(vector<vector<int>> &board) {
	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[n - 1][m - 1] = min(dp[n - 1][m - 1], board[n - 1][m - 1]);
	for (int j = m - 2; j >= 0; j--)
		dp[n - 1][j] = min({0, board[n - 1][j], board[n - 1][j] + dp[n - 1][j + 1]});
	for (int i = n - 2; i >= 0; i--)
		dp[i][m - 1] = min({0, board[i][m - 1], board[i][m - 1] + dp[i + 1][m - 1]});
	for (int i = n - 2; i >= 0; i--)
		for (int j = m - 2; j >= 0; j--)
			dp[i][j] = min({0, board[i][j], board[i][j] + max(dp[i][j + 1], dp[i + 1][j])});
	return abs(dp[0][0]) + 1;
}