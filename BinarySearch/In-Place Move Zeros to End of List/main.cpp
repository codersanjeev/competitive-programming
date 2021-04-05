vector<int> solve(vector<int> &nums) {
	int i = 0, j = 0, n = nums.size();
	while (j < n) {
		if (nums[j] != 0) {
			nums[i++] = nums[j++];
		} else {
			j++;
		}
	}
	while (i < n) {
		nums[i++] = 0;
	}
	return nums;
}