vector<int> dx = { 0, 1, 0, -1};
vector<int> dy = { -1, 0, 1, 0};

void dfs(vector<vector<char>> &board, int i, int j) {
	int n = board.size();
	int m = board[0].size();
	board[i][j] = '$';
	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
			dfs(board, x, y);
		}
	}
}

void Solution::solve(vector<vector<char>> &board) {
	int n = board.size();
	int m = board[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
				dfs(board, i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '$') {
				board[i][j] = 'O';
			}
		}
	}
}
