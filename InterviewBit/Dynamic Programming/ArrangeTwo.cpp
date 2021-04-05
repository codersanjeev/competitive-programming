int Solution::arrange(string horses, int k) {
	int n = horses.size();
	if (k > n) {
		return -1;
	}
	vector<int> dp(n, 0);
	vector<int> dpt(n, 0);
	vector<int> black(n, 0);
	vector<int> white(n, 0);
	for (int i = 0; i < n; i++) {
		black[i] = (horses[i] == 'B' ? 1 : 0);
		if (i > 0) {
			black[i] += black[i - 1];
		}
		white[i] = (horses[i] == 'W' ? 1 : 0);
		if (i > 0) {
			white[i] += white[i - 1];
		}
		dp[i] = black[i] * white[i];
		dpt[i] = black[i] * white[i];
	}
	for (int stable = 2; stable <= k; stable++) {
		for (int j = 1; j < n; j++) {
			int mn = INT_MAX;
			for (int k = stable - 2; k < j; k++) {
				mn = min(mn, dpt[k] + (white[j] - white[k]) * (black[j] - black[k]));
			}
			dp[j] = mn;
		}
		dpt = dp;
	}
	return dp[n - 1];
}
