class Solution {
  public:
	int findNumberOfLIS(vector<int> &nums) {
		int n = nums.size();
		if (n < 2) {
			return n;
		}
		vector<int> dp(n, 1), ans(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					if (dp[i] == 1 + dp[j]) {
						ans[i] += ans[j];
					} else if (dp[i] < 1 + dp[j]) {
						dp[i] = 1 + dp[j];
						ans[i] = ans[j];
					}
				}
			}
		}
		int mx = *max_element(dp.begin(), dp.end()), cnt = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] == mx) {
				cnt += ans[i];
			}
		}
		return cnt;
	}
};