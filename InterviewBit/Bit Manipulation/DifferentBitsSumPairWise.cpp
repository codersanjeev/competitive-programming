int Solution::cntBits(vector<int> &arr) {
	long long n = (long long) arr.size();
	const long long mod = (long long)(1000000007LL);
	long long ans = 0LL;
	for (long long i = 0LL; i < 32LL; i++) {
		long long zeros = 0LL;
		long long ones = 0LL;
		for (auto ele : arr) {
			if ((1LL << i) & (long long)ele) {
				ones++;
			} else {
				zeros++;
			}
		}
		ans += (2LL * (ones % mod) * (zeros % mod)) % mod;
	}
	return ans % mod;
}
