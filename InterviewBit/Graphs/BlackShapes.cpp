vector<int> dx = { 0, 1, 0, -1};
vector<int> dy = { -1, 0, 1, 0};

void dfs(vector<string> &board, int i, int j) {
	int n = board.size();
	int m = board[0].size();
	board[i][j] = 'O';
	for (int ii = 0; ii < 4; ii++) {
		int x = i + dx[ii];
		int y = j + dy[ii];
		if (x >= 0 && y >= 0 && x < n && y < m && board[x][y] == 'X') {
			dfs(board, x, y);
		}
	}
}

int Solution::black(vector<string> &board) {
	int n = board.size();
	int m = board[0].size();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'X') {
				dfs(board, i, j);
				cnt++;
			}
		}
	}
	return cnt;
}
