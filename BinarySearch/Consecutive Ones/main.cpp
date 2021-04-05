bool solve(vector<int> &nums) {
	int n = nums.size(), i = 0;
	bool ok = false;
	while (i < n) {
		while (i < n && nums[i] == 1) {
			ok = true;
			i++;
		}
		if (ok) { break; }
		i++;
	}
	while (i < n) {
		if (nums[i] == 1) {
			return false;
		}
		i++;
	}
	return true;
}