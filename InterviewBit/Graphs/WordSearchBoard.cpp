int dfs(vector<string> &board, string word, int i, int j, int m, int n, int x) {
	if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[x]) {
		return 0;
	}
	if (x == word.size() - 1) {
		return 1;
	}
	return dfs(board, word, i + 1, j, m, n, x + 1) || dfs(board, word, i, j + 1, m, n, x + 1) || dfs(board, word, i, j - 1, m, n, x + 1) || dfs(board, word, i - 1, j, m, n, x + 1);
}

int Solution::exist(vector<string> &board, string word) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == word[0]) {
				if (dfs(board, word, i, j, m, n, 0)) {
					return 1;
				}
			}
		}
	}
	return 0;
}
