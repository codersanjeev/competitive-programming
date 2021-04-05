long long binpow(long long a, long long b, long long m) {
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

int Solution::Mod(int A, int B, int C) {
	while (A < 0) {
		A += C;
		if (A >= 0) {
			A %= C;
		}
	}
	if (A == 0) {
		return 0;
	}
	if (B == 0) {
		return 1;
	}
	return binpow(A, B, C);
}
