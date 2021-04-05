const long long mod = 1e9 + 7;
const long long N = 101;

vector<vector<long long>> nCr(N, vector<long long>(N, -1));
vector<long long> dp(N, -1);

long long findNcR(long long n, long long r) {
	if (nCr[n][r] != -1) {
		return nCr[n][r] % mod;
	}
	if (r > n) {
		nCr[n][r] = 0;
		return nCr[n][r];
	}
	if (n <= 1 || r == 0) {
		nCr[n][r] = 1;
		return nCr[n][r];
	}
	nCr[n][r] = (findNcR(n - 1, r - 1) % mod + findNcR(n - 1, r) % mod) % mod;
	return nCr[n][r] % mod;
}

long long getLeft(long long n) {
	if (n == 1) {
		return 0;
	}
	long long h = log2(n);
	long long numh = (1 << h);
	long long last = n - ((1 << h) - 1);
	if (last >= (numh / 2)) {
		return (1 << h) - 1;
	} else {
		return (1 << h) - 1 - ((numh / 2) - last);
	}
}

int Solution::solve(int n) {
	if (n <= 1) {
		return 1;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	long long left = getLeft(n);
	dp[n] = (findNcR(n - 1, left) % mod * solve(left) % mod * solve(n - left - 1) % mod) % mod;
	return dp[n] % mod;
}
