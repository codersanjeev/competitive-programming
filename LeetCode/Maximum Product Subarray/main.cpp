class Solution {
  public:
	int maxProduct(vector<int> &nums) {
		int mx = nums[0], mn = mx, ans = mx;
		for (int i = 1; i < nums.size(); i++) {
			int temp = mx;
			mx = max({nums[i], mx *nums[i], mn *nums[i]});
			mn = min({nums[i], temp *nums[i], mn *nums[i]});
			ans = max(ans, mx);
		}
		return ans;
	}
};