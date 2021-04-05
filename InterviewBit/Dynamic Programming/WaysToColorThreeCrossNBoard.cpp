int Solution::solve(int n) {
	long long colorTwo = 12LL, colorThree = 24LL, temp = 0LL, mod = 1e9 + 7;
	for (long long i = 2LL; i <= n; i++) {
		temp = colorThree;
		colorThree = (11LL * colorThree + 10LL * colorTwo) % mod;
		colorTwo = (5LL * temp + 7LL * colorTwo) % mod;
	}
	return (colorTwo + colorThree) % mod;
}
