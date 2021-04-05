const int mod = 1e9 + 7;

vector<vector<int>> dp(1001, vector<int>(1001));

int Solution::solve(int N, int S) {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= S; j++) {
			int cnt = 0;
			for (int d = 0; d < 10 && d <= j; d++) {
				cnt = (cnt % mod + dp[i - 1][j - d] % mod) % mod;
			}
			dp[i][j] = cnt % mod;
		}
	}
	return dp[N][S];
}
