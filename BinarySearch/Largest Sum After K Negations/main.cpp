int solve(vector<int> &nums, int k) {
	if (nums.empty()) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int i = 0, n = nums.size();
	while (i < n && k > 0 && nums[i] <= 0) {
		nums[i] *= -1;
		k--;
		i++;
	}
	if (i > 0 && k % 2 == 1) {
		nums[i - 1] *= -1;
	} else if (i == 0 && k % 2 == 1) {
		nums[i] *= -1;
	}
	return accumulate(nums.begin(), nums.end(), 0);
}