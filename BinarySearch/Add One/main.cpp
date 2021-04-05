vector<int> solve(vector<int> &nums) {
	int i = nums.size() - 1, carry = 1;
	vector<int> ans;
	while (i >= 0) {
		int curr = nums[i] + carry;
		ans.push_back(curr % 10);
		carry = curr / 10;
		i--;
	}
	if (carry > 0) {
		ans.push_back(carry);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}