int solve(string s) {
	if (s.empty()) {
		return 0;
	}
	int n = s.size(), ans = 1, curr = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			curr++;
		} else {
			ans = max(ans, curr);
			curr = 1;
		}
	}
	return max(ans, curr);
}