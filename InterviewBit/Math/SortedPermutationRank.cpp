int f(int n, int m) {
	int ans = 1;
	if (n == 0 || n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	for (int i = 2; i <= n; i++) {
		ans = (ans * i) % m;
	}
	return ans;
}

int Solution::findRank(string s) {
	int n = s.size();
	const int mod = 1000003;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int curr = 0;
		for (int j = i + 1; j < n; j++) {
			if (s[j] < s[i]) {
				curr++;
			}
		}
		ans = (ans + (f(n - i - 1, mod) * curr) % mod) % mod;
	}
	return ans + 1;
}