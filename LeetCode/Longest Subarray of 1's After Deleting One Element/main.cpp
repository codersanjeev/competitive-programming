class Solution {
  public:
	int longestSubarray(vector<int> &nums) {
		int n = nums.size(), ans = 0;
		vector<int> pre(n, 0), pos(n, 0);
		if (nums[0] == 1) {
			pre[0] = 1;
		}
		if (nums[n - 1] == 1) {
			pos[n - 1] = 1;
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] == 1) {
				pre[i] = pre[i - 1] + 1;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] == 1) {
				pos[i] = pos[i + 1] + 1;
			}
		}
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, pre[i - 1] + pos[i + 1]);
		}
		return max(ans, pre[n - 1] - 1);
	}
};