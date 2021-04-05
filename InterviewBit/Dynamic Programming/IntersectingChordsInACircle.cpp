long long modPow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int Solution::chordCnt(int A) {
	long long n = (long long) A;
	long long m = (long long) 2 * A;
	long long mod = 1000000007LL;
	vector<long long> fact(m + 1, 1);
	for (long long i = 2; i <= m; i++) {
		fact[i] = (i % mod * fact[i - 1] % mod) % mod;
	}
	long long x = modPow(fact[n], mod - 2, mod);
	long long y = modPow(fact[n + 1], mod - 2, mod);
	long long z = fact[m];
	long long ans = (x % mod * y % mod) % mod;
	return (ans % mod * z % mod) % mod;
}
