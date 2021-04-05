vector<int> solve(vector<int> &nums) {
	int n = nums.size(), res = 1;
	vector<int> ans(n);
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		ans[i] = ans[i - 1] * nums[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		ans[i] *= res;
		res *= nums[i];
	}
	return ans;
}