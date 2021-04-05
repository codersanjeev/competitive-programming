vector<vector<int>> Solution::prettyPrint(int n) {
	int m = (2 * n) - 1;
	vector<vector<int>> ans(m, vector<int>(m));
	int mn = 0, mx = m;
	while (n > 0) {
		for (int i = mn; i < mx; i++) {
			for (int j = mn; j < mx; j++) {
				ans[i][j] = n;
			}
		}
		n--;
		mx--;
		mn++;
	}
	return ans;
}
