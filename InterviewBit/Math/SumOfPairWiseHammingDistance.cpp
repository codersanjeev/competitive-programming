int Solution::hammingDistance(const vector<int> &A) {
	const long long mod = 1000000007;
	long long n = A.size();
	if (n <= 0) {
		return 0;
	}
	long long ans = 0;
	for (long long i = 0; i < 32; i++) {
		long long ones = 0;
		for (auto ele : A) {
			if (ele & (1 << i)) {
				ones++;
			}
		}
		long long zeros = n - ones;
		ans = (ans % mod + (2 * ones * zeros) % mod) % mod;
	}
	return ans % mod;
}
