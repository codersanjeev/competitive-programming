int Solution::findMedian(vector<vector<int>> &arr) {
	int m = arr.size();
	int n = arr[0].size();
	int mn = INT_MAX;
	int mx = INT_MIN;
	int desire = ((m * n) + 1) / 2;
	for (int i = 0; i < m; i++) {
		mn = min(mn, arr[i][0]);
		mx = max(mx, arr[i][n - 1]);
	}
	int lo = mn, hi = mx;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int cnt = 0;
		for (auto row : arr) {
			cnt += upper_bound(row.begin(), row.end(), mid) - row.begin();
		}
		if (cnt < desire) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	return lo;
}