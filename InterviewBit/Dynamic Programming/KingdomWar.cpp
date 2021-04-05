int Solution::solve(vector<vector<int> > &board) {
	int n = board.size();
	int m = board[0].size();
	for (int j = m - 2; j >= 0; j--) {
		board[n - 1][j] += board[n - 1][j + 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		board[i][m - 1] += board[i + 1][m - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			board[i][j] += (board[i + 1][j] + board[i][j + 1] - board[i + 1][j + 1]);
		}
	}
	int ans = INT_MIN;
	for (auto &row : board) {
		for (auto &ele : row) {
			ans = max(ans, ele);
		}
	}
	return ans;
}
