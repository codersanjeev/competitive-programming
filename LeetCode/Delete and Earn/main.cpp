class Solution {
  public:

	int rob(vector<int> &nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		} else if (n == 1) {
			return nums[0];
		} else if (n == 2) {
			return max(nums[0], nums[1]);
		}
		vector<int> dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp.back();
	}

	int deleteAndEarn(vector<int> &nums) {
		vector<int> amount(10001, 0);
		for (const auto &ele : nums) {
			amount[ele] += ele;
		}
		return rob(amount);
	}
};