vector<vector<int>> Solution::queenAttack(vector<string> &board) {
	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 0));
	vector<int> dx = { -1, -1, -1, +0, +1, +1, +1, +0};
	vector<int> dy = { -1, +0, +1, +1, +1, +0, -1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '0') {
				continue;
			}
			for (int d = 0; d < 8; d++) {
				int x = i + dx[d];
				int y = j + dy[d];
				while (x >= 0 && y >= 0 && x < n && y < m) {
					ans[x][y]++;
					if (board[x][y] == '1') {
						break;
					}
					x += dx[d];
					y += dy[d];
				}
			}
		}
	}
	return ans;
}
