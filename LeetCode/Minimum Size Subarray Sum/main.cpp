class Solution {
  public:
	int minSubArrayLen(int s, vector<int> &nums) {
		int i = 0, j = 0, n = nums.size(), sum = 0, ans = INT_MAX;
		while (j < n) {
			sum += nums[j++];
			while (sum >= s) {
				ans = min(ans, j - i);
				sum -= nums[i++];
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};