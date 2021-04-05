string lcp(const string &a, const string &b) {
	int n = a.size(), m = b.size(), i = 0, j = 0;
	string ans = "";
	while (i < n && j < m && a[i] == b[j]) {
		ans += a[i];
		i++;
		j++;
	}
	return ans;
}

string solve(vector<string> &arr) {
	if (arr.empty()) {
		return "";
	}
	string ans = arr[0];
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		ans = lcp(ans, arr[i]);
	}
	return ans;
}