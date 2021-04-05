int solve(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size(), ans = 0;
	vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + delta[k].first;
				int ny = j + delta[k].second;
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (matrix[i][j] == 1 && matrix[nx][ny] == 0) {
						ans++;
					}
				} else if (matrix[i][j] == 1) {
					ans++;
				}
			}
		}
	}
	return ans;
}