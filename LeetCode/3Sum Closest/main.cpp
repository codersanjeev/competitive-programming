class Solution {
  public:
	int threeSumClosest(vector<int> &nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans = 0, diff = INT_MAX;
		for (int i = 0; i < n; i++) {
			int curr = target - nums[i];
			int j = i + 1, k = n - 1;
			while (j < k) {
				int currentSum = nums[j] + nums[k];
				if (currentSum > curr) {
					k--;
				} else {
					j++;
				}
				if (abs(currentSum + nums[i] - target) <= diff) {
					diff = abs(currentSum + nums[i] - target);
					ans = currentSum + nums[i];
				}
			}
		}
		return ans;
	}
};