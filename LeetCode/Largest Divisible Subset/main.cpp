class Solution {
  public:
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		int n = nums.size(), mx = -1;
		if (n < 2) {
			return nums;
		}
		sort(nums.begin(), nums.end());
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
					dp[i] = 1 + dp[j];
				}
			}
			mx = max(mx, dp[i]);
		}
		vector<int> ans;
		for (int i = n - 1; i >= 0; i--) {
			if ((dp[i] == mx && !ans.empty() && ans.back() % nums[i] == 0) || (dp[i] == mx && ans.empty())) {
				ans.push_back(nums[i]);
				mx--;
			}
		}
		return ans;
	}
};