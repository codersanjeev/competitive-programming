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
		int temp = nums.back();
		nums.pop_back();
		int x = robUtil(nums);
		nums.push_back(temp);
		vector<int> arr;
		for (int i = 1; i < n; i++) {
			arr.push_back(nums[i]);
		}
		int y = robUtil(arr);
		return max(x, y);
	}
  private:
	int robUtil(vector<int> &nums) {
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
};