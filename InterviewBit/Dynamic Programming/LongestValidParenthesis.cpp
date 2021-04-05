int Solution::longestValidParentheses(string s) {
	int n = s.size();
	if (n < 2) { return 0; }
	vector<int> dp(n, 0);
	for (int i = 1; i < n; i++) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') { dp[i] = 2 + dp[i - 2]; }
			else {
				if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
				}
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}
