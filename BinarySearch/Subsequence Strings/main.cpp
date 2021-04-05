bool solve(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	if (n > m) {
		return false;
	}
	if (n == m) {
		return s1 == s2;
	}
	if (m == 0) {
		return false;
	}
	if (n == 0) {
		return true;
	}
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (s1[j] == s2[i]) {
			if (j == n - 1) {
				return true;
			}
			j++;
		}
	}
	return false;
}