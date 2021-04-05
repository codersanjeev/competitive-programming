int solve(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	int i = 0, j = nums.size() - 1, ans = INT_MIN;
	while (i < j) {
		int curr = nums[i] + nums[j];
		if (curr < target) {
			ans = max(ans, curr);
			i++;
		} else {
			j--;
		}
	}
	return ans;
}