int Solution::solve(vector<int> &arr, int k) {

	int n = arr.size();
	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	if (n == 0 || k == 0) {
		return 0;
	}
	if (k >= n) {
		ans = arr[n - 1] - arr[0];
	}
	else {
		for (int i = 0; i <= n - k; i++)
			ans = min(ans, arr[i + k - 1] - arr[i]);
	}
	return ans;

}
