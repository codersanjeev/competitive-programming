int solve(vector<int> &nums) {
	if (nums.size() == 0) {
		return 0;
	}
	int incl = max(0, nums[0]), excl = 0;
	for (int i = 1; i < nums.size(); i++) {
		int temp = incl;
		incl = max(excl + nums[i], incl);
		excl = temp;
	}
	return incl;
}