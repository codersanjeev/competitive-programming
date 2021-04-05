int Solution::largestRectangleArea(vector<int> &arr) {
	int n = arr.size();
	if (n == 0) {
		return 0;
	}
	vector<int> f(n), g(n);
	f[0] = -1;
	g[n - 1] = n;
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j >= 0 && arr[j] >= arr[i]) {
			j = f[j];
		}
		f[i] = j;
	}
	for (int i = n - 2; i >= 0; i--) {
		int j = i + 1;
		while (j < n && arr[j] >= arr[i]) {
			j = g[j];
		}
		g[i] = j;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i] * (g[i] - f[i] - 1));
	}
	return ans;
}
