int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
	if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
	if (g[i][j] == 2) return s == t_s ? 1 : 0;
	g[i][j] = -1;
	int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) + dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
	g[i][j] = 0;
	return paths;
}

int Solution::solve(vector<vector<int>> &board) {

	int n = board.size();
	int m = board[0].size();

	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				x = i;
				y = j;
			}
			if (board[i][j] != -1) {
				z++;
			}
		}
	}

	return dfs(board, x, y, 1, z);

}
