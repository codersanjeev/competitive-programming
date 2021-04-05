class Solution {
  public:
	int numIslands(vector<vector<char>> &grid) {
		int m = grid.size(), n = grid[0].size(), ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					ans++;
					dfs(grid, i, j, m, n);
				}
			}
		}
		return ans;
	}
  private:
	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};

	void dfs(vector<vector<char>> &grid, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') {
			return;
		}
		grid[i][j] = '0';
		for (int k = 0; k < 4; k++) {
			dfs(grid, i + dx[k], j + dy[k], n, m);
		}
	}
};