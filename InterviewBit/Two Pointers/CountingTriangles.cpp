int Solution::nTriang(vector<int> &arr) {
	const long long mod = (long long) (1e9 + 7);
	long long n = (long long) arr.size();
	sort(arr.begin(), arr.end());
	long long ans = 0LL;
	for (long long i = 0; i < n - 2; i++) {
		long long k = i + 2;
		for (long long j = i + 1; j < n - 1; j++) {
			while (k < n && ((long long)arr[i] + (long long)arr[j]) > (long long)arr[k]) {
				k++;
			}
			ans = (ans % mod + (k - j - 1) % mod) % mod;
		}
	}
	return ans % mod;
}
