class Solution {
  public:
	double findMaxAverage(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			nums[i] += nums[i - 1];
		}
		int j = k - 1;
		double ans = -1e9;
		while (j < n) {
			int i = j - k + 1;
			double curr = nums[j];
			if (i > 0) curr -= nums[i - 1];
			ans = max(ans, (curr * 1.0) / k);
			j++;
		}
		return ans;
	}
};