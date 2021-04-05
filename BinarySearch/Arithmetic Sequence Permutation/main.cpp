bool solve(vector<int> &nums) {
	int n = nums.size();
	if (n < 3) {
		return true;
	}
	sort(nums.begin(), nums.end());
	int diff = nums[1] - nums[0];
	for (int i = 2; i < n; i++) {
		if (nums[i] - nums[i - 1] != diff) {
			return false;
		}
	}
	return true;
}