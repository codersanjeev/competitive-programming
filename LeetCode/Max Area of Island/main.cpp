class Solution {
  public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					int curr = dfs(grid, i, j, n, m);
					ans = max(ans, curr);
				}
			}
		}
		return ans;
	}

	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};

	int dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) {
			return 0;
		}
		grid[i][j] = -1;
		int ans = 1;
		for (int k = 0; k < 4; k++) {
			ans += dfs(grid, i + dx[k], j + dy[k], n, m);
		}
		return ans;
	}
};