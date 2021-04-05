class Solution {
  public:
	int orangesRotting(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size(), ans = 0;
		queue<pair<int, int>> q;
		const int M = 1e9;
		vector<vector<int>> dist(m, vector<int>(n, M));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 2) {
					q.push({i, j});
					grid[i][j] = -1;
					dist[i][j] = 0;
				}
			}
		}
		vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int x = curr.first;
			int y = curr.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + delta[k].first;
				int ny = y + delta[k].second;
				if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
					q.push({nx, ny});
					grid[nx][ny] = -1;
					dist[nx][ny] = 1 + dist[x][y];
				}
			}
		}
		for (const auto &row : grid) {
			for (const auto &ele : row) {
				if (ele == 1) {
					return -1;
				}
			}
		}
		for (const auto &row : dist) {
			for (const auto &ele : row) {
				if (ele != M) {
					ans = max(ans, ele);
				}
			}
		}
		return ans;
	}
};