int Solution::solve(const vector<int> &arr) {
	int n = arr.size(), ans = 1;
	if (n <= 2) {
		return n;
	}
	vector<vector<int>> dp(n, vector<int>(n, 0));
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int diff = arr[j] - arr[i];
			dp[i][j] = 2;
			int ele = arr[i] - diff;
			if (mp.find(ele) != mp.end()) {
				int index = mp[ele];
				dp[i][j] = dp[index][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		mp[arr[i]] = i;
	}
	return ans;
}
