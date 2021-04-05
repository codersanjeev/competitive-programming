void Solution::setZeroes(vector<vector<int> > &arr) {
	int m = arr.size();
	int n = arr[0].size();
	set<int> rows, cols;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	for (auto i : rows) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	for (auto j : cols) {
		for (int i = 0; i < m; i++) {
			arr[i][j] = 0;
		}
	}
}
