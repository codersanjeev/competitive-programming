const long long mod = 1e9 + 7;
long long dp[51][51];
long long nCr[51][51];

long long f(long long n, long long m) {
	if (n <= 1) {
		return m == 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long x = i - 1;
		long long y = n - i;
		long long temp = 0;
		for (long long j = 0; j < m - 1; j++) {
			if (dp[x][j] == -1) {
				dp[x][j] = f(x, j);
			}
			if (dp[y][m - 1] == -1) {
				dp[y][m - 1] = f(y, m - 1);
			}
			temp += (dp[x][j] * dp[y][m - 1]) % mod;
		}
		for (long long j = 0; j < m - 1; j++) {
			if (dp[y][j] == -1) {
				dp[y][j] = f(y, j);
			}
			if (dp[x][m - 1] == -1) {
				dp[x][m - 1] = f(x, m - 1);
			}
			temp += (dp[y][j] * dp[x][m - 1]) % mod;
		}
		if (dp[x][m - 1] == -1) {
			dp[x][m - 1] = f(x, m - 1);
		}
		if (dp[y][m - 1] == -1) {
			dp[y][m - 1] = f(y, m - 1);
		}
		temp += (dp[x][m - 1] * dp[y][m - 1]) % mod;
		ans += (temp * nCr[x + y][y]);
	}
	return ans % mod;
}

int Solution::cntPermBST(int A, int B) {
	memset(nCr, 0, sizeof(nCr));
	memset(dp, -1, sizeof(dp));
	for (long long i = 0; i < 51; i++) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
	}
	for (long long i = 2; i < 51; i++) {
		for (long long j = 1; j < i; j++) {
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
		}
	}
	return f(A, B);
}
