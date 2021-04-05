vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

void dfs(vector<vector<int>> &matrix, int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] != 1) {
		return;
	}
	matrix[i][j] = -1;
	for (int k = 0; k < 4; k++) {
		dfs(matrix, i + delta[k].first, j + delta[k].second, n, m);
	}
}

int solve(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size(), ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 1) {
				ans++;
				dfs(matrix, i, j, n, m);
			}
		}
	}
	return ans;
}