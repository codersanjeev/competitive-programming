vector<vector<int>> dp(51, vector<int>(51, -1));

int nCr(int n, int r) {
	if (dp[n][r] != -1) {
		return dp[n][r];
	}
	if (n == 1 || r == 1 || n == r) {
		return dp[n][r] = 1;
	}
	return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

vector<int> solve(int n) {
	vector<int> ans;
	ans.reserve(n + 1);
	for (int i = 1; i <= n + 1; i++) {
		ans.push_back(nCr(n + 1, i));
	}
	return ans;
}