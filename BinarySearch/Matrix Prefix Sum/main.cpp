vector<vector<int>> solve(vector<vector<int>> &matrix) {
	if (matrix.empty()) {
		return matrix;
	}
	int n = matrix.size(), m = matrix[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			matrix[i][j] += matrix[i][j - 1];
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			matrix[i][j] += matrix[i - 1][j];
		}
	}
	return matrix;
}