int Solution::minimumTotal(vector<vector<int>> &board) {
	int m = board.size();
	vector<int> dp = board[m - 1];
	for (int i = m - 2; i >= 0; i--) {
		for (int j = 0; j < board[i].size(); j++) {
			dp[j] = board[i][j] + min(dp[j], dp[j + 1]);
		}
	}
	return dp[0];
}
