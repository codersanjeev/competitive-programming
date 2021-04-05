class Solution {
  public:
	int numberOfSubarrays(vector<int> &nums, int k) {
		for (auto &ele : nums) {
			ele %= 2;
		}
		// count of subarrays having k ones in it???
		// count of subarrays having sum k
		map<int, int> mp;
		int n = nums.size(), sum = 0, ans = 0;
		mp[0] = 1;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			if (mp[sum - k] > 0) {
				ans += mp[sum - k];
			}
			mp[sum]++;
		}
		return ans;
	}
};