class Solution {
  public:
	int calculateMinimumHP(vector<vector<int>> &dungeon) {
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		int ans = calculateMinimumHPUtil(dungeon, dp, 0, 0, m, n);
		return ans;
	}

  private:
	int calculateMinimumHPUtil(const vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m) {
			return 1e9;
		}
		if (i == n - 1 && j == m - 1) {
			return (grid[i][j] <= 0 ? -grid[i][j] + 1 : 1);
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int left = calculateMinimumHPUtil(grid, dp, i, j + 1, n, m);
		int bottom = calculateMinimumHPUtil(grid, dp, i + 1, j, n, m);
		int ans = -grid[i][j] + min(left, bottom);
		return dp[i][j] = (ans <= 0 ? 1 : ans);
	}
};