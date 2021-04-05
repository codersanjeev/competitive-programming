class Solution {
  public:
	bool canPartition(vector<int> &nums) {
		int n = nums.size(), s = accumulate(nums.begin(), nums.end(), 0);
		if (s % 2 == 1) {
			return false;
		}
		s /= 2;
		vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, -1));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= s; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = false;
				} else if (nums[i - 1] > j) {
					dp[i][j] = dp[i - 1][j];
				} else if (nums[i - 1] == j) {
					dp[i][j] = true;
				} else {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		return dp[n][s];
	}
};