
long long modpow(long long x, long long y, long long m) {
	long long ans = 1;
	while (y) {
		if (y & 1) {
			ans *= x;
			ans %= m;
		}
		x *= x;
		x %= m;
		y >>= 1;
	}
	return ans;
}

int Solution::findRank(string A) {
	long long ans = 0;
	long long n = A.size();
	const long long mod = 1000003;
	vector<long long> fact(n + 1);
	vector<long long> invfact(n + 1);
	unordered_map<char, long long> mp;
	fact[0] = 1;
	fact[1] = 1;
	for (long long i = 2; i <= n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	for (long long i = 0; i <= n; i++) {
		invfact[i] = modpow(fact[i], mod - 2LL, mod);
	}
	int cnt = 26;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		mp[ch] = cnt;
		cnt++;
	}
	cnt = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		mp[ch] = cnt;
		cnt++;
	}
	vector<long long> freq(52, 0);
	for (long long i = 0; i < n; i++) {
		freq[mp[A[i]]]++;
	}
	for (long long i = 0; i < n; i++) {
		long long numerator = 0;
		long long denominator = 1;
		for (auto ele : freq) {
			denominator = (denominator % mod * fact[ele] % mod) % mod;
		}
		long long curr = mp[A[i]] - 1;
		while (curr >= 0) {
			numerator += freq[curr];
			curr--;
		}
		denominator = modpow(denominator, mod - 2, mod);
		ans = (ans % mod + (numerator % mod * denominator % mod * fact[n - i - 1] % mod) % mod) % mod;
		freq[mp[A[i]]]--;
	}
	++ans;
	return (int)(ans % mod);
}