int solve(vector<int> &nums) {
	int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
	return sum - ((n * (n - 1)) / 2);
}