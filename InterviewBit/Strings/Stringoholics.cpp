int Solution::solve(vector<string> &A) {
	long long n = A.size();
	vector<long long> v(n);
	for (long long i = 0; i < n; i++) {
		long long x = A[i].size();
		if (x <= 1) {
			v[i] = 1;
		} else {
			long long k = 1, c = 0;
			while (1) {
				c = (k * (k + 1)) / 2;
				if (c % x == 0) {
					v[i] = k;
					break;
				}
				k++;
			}
		}
	}
	long long ans = 1;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n && v[i] != 1; j++) {
			v[j] = v[j] / __gcd(v[i], v[j]);
		}
		ans = (long long)(ans % 1000000007 * (v[i]) % 1000000007) % 1000000007;
	}
	return ans;
}
