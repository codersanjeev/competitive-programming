int Solution::seats(string arr) {
	int n = arr.size();
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'x') {
			pos.push_back(i);
		}
	}
	int m = pos.size();
	int mid = m / 2, ans = 0;
	for (int i = 0; i < m; i++) {
		ans = (ans + abs(pos[i] - pos[mid]) - abs(i - mid)) % mod;
	}
	return ans;
}
