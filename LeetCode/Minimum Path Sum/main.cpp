class Solution {
  public:
	int minPathSum(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, -1));
		return minPathSumUtil(grid, dp, 0, 0, n, m);
	}

  private:
	int minPathSumUtil(const vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m) {
			return 1e9;
		}
		if (i == n - 1 && j == m - 1) {
			return grid[i][j];
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int left = minPathSumUtil(grid, dp, i, j + 1, n, m);
		int bottom = minPathSumUtil(grid, dp, i + 1, j, n, m);
		return dp[i][j] = grid[i][j] + min(left, bottom);
	}
};