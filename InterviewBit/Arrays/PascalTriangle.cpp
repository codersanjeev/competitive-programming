vector<vector<int>> Solution::solve(int n) {
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; i++) {
		vector<int> temp(i + 1);
		temp[0] = 1;
		for (int j = 1; j < i; j++) {
			temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
		temp[i] = 1;
		ans[i] = temp;
	}
	return ans;
}