int solve(string message) {
	int n = message.size();
	if (n == 0 || message[0] == '0') {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 0;
		if (message[i - 1] != '0') {
			dp[i] = dp[i - 1];
		}
		int curr = message[i - 1] - '0';
		curr += 10 * (message[i - 2] - '0');
		if (curr >= 10 && curr <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[n];
}