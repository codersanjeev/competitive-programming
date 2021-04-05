bool solve(string s, string t) {
	int n = s.size(), m = t.size();
	if (n != m) {
		return false;
	}
	vector<int> a(256, 0), b(256, 0);
	for (int i = 0; i < n; i++) {
		int x = (int) s[i];
		int y = (int) t[i];
		if (a[x] != b[y]) {
			return false;
		}
		a[x] = b[y] = i + 1;
	}
	return true;
}