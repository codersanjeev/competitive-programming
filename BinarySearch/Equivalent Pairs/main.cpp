int solve(vector<int> &nums) {
	int ans = 0, n = nums.size();
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[nums[i]]++;
	}
	for (const auto &ele : mp) {
		ans += (ele.second * (ele.second - 1)) / 2;
	}
	return ans;
}