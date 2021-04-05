int solve(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size(), ans = 0;
	vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (matrix[i][j] != -1) {
					pq.push({matrix[i][j], {i, j}});
					matrix[i][j] = -1;
				}
			}
		}
	}
	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();
		int h = curr.first;
		int i = curr.second.first;
		int j = curr.second.second;
		for (int k = 0; k < 4; k++) {
			int nx = i + dirs[k].first;
			int ny = j + dirs[k].second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != -1) {
				ans += max(0, h - matrix[nx][ny]);
				pq.push({max(h, matrix[nx][ny]), {nx, ny}});
				matrix[nx][ny] = -1;
			}
		}
	}
	return ans;
}