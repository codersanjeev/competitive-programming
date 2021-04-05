bool solve(vector<int> &nums) {
	int idx = 0, reach = 0, n = nums.size();
	while (idx <= reach && idx < n) {
		reach = max(reach, idx + nums[idx]);
		idx++;
	}
	return reach >= n - 1;
}