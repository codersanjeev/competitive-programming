int Solution::maxProduct(const vector<int> &arr) {
	int pre = 1, pos = 1, ans = INT_MIN, n = arr.size();
	for (int i = 0; i < n; i++) {
		pre *= arr[i];
		pos *= arr[n - i - 1];
		ans = max(ans, max(pre, pos));
		pre = pre == 0 ? 1 : pre;
		pos = pos == 0 ? 1 : pos;
	}
	return ans;
}
