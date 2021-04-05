int Solution::solve(vector<vector<int>> &board) {
	int m = board.size();
	int n = board[0].size();
	if (m == 0) {
		return 0;
	}
	vector<vector<int>> arr(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				arr[i][j] = board[i][j];
			} else {
				if (board[i][j] == 1) {
					arr[i][j] = 1 + arr[i - 1][j];
				} else {
					arr[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		sort(arr[i].begin(), arr[i].end());
		int curr = arr[i][0] * n;
		for (int j = 1; j < n; j++) {
			curr = max(curr, arr[i][j] * (n - j));
		}
		ans = max(ans, curr);
	}
	return ans;
}
