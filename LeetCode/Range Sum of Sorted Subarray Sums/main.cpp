class Solution {
  public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		const int mod = 1e9 + 7;
		vector<int> sums;
		for (int i = 1; i < n; i++) {
			nums[i] = (nums[i] + nums[i - 1]) % mod;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int curr = nums[j];
				if (i > 0) curr = (curr - nums[i - 1] + mod) % mod;
				sums.push_back(curr);
			}
		}
		sort(sums.begin(), sums.end());
		for (int i = 1; i < sums.size(); i++) {
			sums[i] = (sums[i] + sums[i - 1]) % mod;
		}
		left--;
		right--;
		return (left == 0 ? sums[right] : (sums[right] - sums[left - 1] + mod) % mod);
	}
};