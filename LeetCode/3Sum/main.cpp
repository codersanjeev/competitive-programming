class Solution {
  public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n && nums[i] <= 0; i++) {
			int target = nums[i] * -1;
			int j = i + 1, k = n - 1;
			while (j < k) {
				int curr = nums[j] + nums[k];
				if (curr > target) {
					k--;
				} else if (curr < target) {
					j++;
				} else {
					vector<int> temp = {nums[i], nums[j], nums[k]};
					while (j < k && nums[j] == temp[1]) {
						j++;
					}
					while (j < k && nums[k] == temp[2]) {
						k--;
					}
					ans.push_back(temp);
				}
			}
			while (i + 1 < n && nums[i + 1] == nums[i]) {
				i++;
			}
		}
		return ans;
	}

};