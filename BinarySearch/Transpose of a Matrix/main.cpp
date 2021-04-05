vector<vector<int>> solve(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	return matrix;
}