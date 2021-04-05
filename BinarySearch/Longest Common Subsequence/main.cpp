int solveUtil(const string &a, const string &b, vector<vector<int>> &dp, int i, int j, int n, int m) {
	if (i == n || j == m) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int x = solveUtil(a, b, dp, i + 1, j + 1, n, m);
	int y = solveUtil(a, b, dp, i, j + 1, n, m);
	int z = solveUtil(a, b, dp, i + 1, j, n, m);
	if (a[i] == b[j]) {
		return dp[i][j] = 1 + x;
	} else {
		return dp[i][j] = max(y, z);
	}
}

int solve(string a, string b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return solveUtil(a, b, dp, 0, 0, n, m);
}