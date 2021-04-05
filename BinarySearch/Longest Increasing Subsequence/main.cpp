int solve(vector<int> &nums) {
	int n = nums.size();
	if (n < 2) {
		return n;
	}
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}