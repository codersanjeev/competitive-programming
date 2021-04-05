bool solve(string s, string t) {
	int n = s.size(), m = t.size(), i = 0, j = 0, cnt = 0;
	if (s == t) {
		return true;
	}
	if (abs(n - m) > 1) {
		return false;
	}
	while (i < n && j < m) {
		if (s[i] != t[j]) {
			if (cnt == 1) {
				return false;
			}
			if (n > m) {
				i++;
			} else if (n < m) {
				j++;
			} else {
				i++;
				j++;
			}
			cnt++;
		} else {
			i++;
			j++;
		}
	}
	if (i < n || j < m) {
		cnt++;
	}
	return cnt == 1;
}