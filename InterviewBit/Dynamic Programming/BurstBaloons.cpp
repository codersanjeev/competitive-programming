int Solution::solve(vector<int> &arr) {

	vector<int> baloons = arr;
	baloons.insert(baloons.begin(), 1);
	baloons.push_back(1);
	int n = arr.size();
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i < n - len + 2; i++) {
			int j = i + len - 1;
			for (int last = i; last <= j; last++) {
				dp[i][j] = max(dp[i][j], dp[i][last - 1] + (baloons[i - 1] * baloons[last] * baloons[j + 1]) + dp[last + 1][j]);
			}
		}
	}
	return dp[1][n];

}
