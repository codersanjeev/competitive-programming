int Solution::lis(const vector<int> &arr) {
	int n = arr.size();
	if (n <= 1) {
		return n;
	}
	vector<int> ans(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				ans[i] = max(ans[i], ans[j] + 1);
			}
		}
	}
	return *max_element(ans.begin(), ans.end());
}
