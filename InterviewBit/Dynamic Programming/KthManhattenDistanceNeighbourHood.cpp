vector<vector<int>> Solution::solve(int k, vector<vector<int> > &matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp = matrix;
	for (int dist = 0; dist < k; dist++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int curr = matrix[i][j];
				int top = (i == 0 ? -1 : matrix[i - 1][j]);
				int bottom = (i == m - 1 ? -1 : matrix[i + 1][j]);
				int left = (j == 0 ? -1 : matrix[i][j - 1]);
				int right = (j == n - 1 ? -1 : matrix[i][j + 1]);
				dp[i][j] = max({curr, top, left, bottom, right});
			}
		}
		matrix = dp;
	}
	return matrix;
}
