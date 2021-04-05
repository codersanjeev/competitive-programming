class Solution {
  public:
	int maxOperations(vector<int> &nums, int k) {
		int ans = 0, i = 0, j = nums.size() - 1;
		sort(nums.begin(), nums.end());
		while (i < j) {
			int curr = nums[i] + nums[j];
			if (curr < k) {
				i++;
			} else if (curr > k) {
				j--;
			} else {
				ans++;
				i++;
				j--;
			}
		}
		return ans;
	}
};