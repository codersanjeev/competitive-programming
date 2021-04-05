class Solution {
  public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		// obstacle : 1
		// space    : 0
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, -1));
		return uniquePathsWithObstaclesUtil(obstacleGrid, dp, 0, 0, n, m);
	}

  private:
	int uniquePathsWithObstaclesUtil(const vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int n, int m) {
		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1) {
			return 0;
		}
		if (i == n - 1 && j == m - 1) {
			return grid[i][j] == 0;
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int left = uniquePathsWithObstaclesUtil(grid, dp, i, j + 1, n, m);
		int right = uniquePathsWithObstaclesUtil(grid, dp, i + 1, j, n, m);
		return dp[i][j] = left + right;
	}
};