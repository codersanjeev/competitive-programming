int findNumberOfPaths(vector<vector<int>> &board, int i, int j, int m, int n) {
	if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 1) {
		return 0;
	}
	if (i == m - 1 && j == n - 1 && board[i][j] == 0) {
		return 1;
	}
	return findNumberOfPaths(board, i + 1, j, m, n) + findNumberOfPaths(board, i, j + 1, m, n);
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> &board) {
	int m = board.size();
	int n = board[0].size();
	return findNumberOfPaths(board, 0, 0, m, n);
}
