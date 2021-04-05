class Solution {
  public:
	vector<vector<int>> fourSum(vector<int> &nums, int key) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int target = key - (nums[i] + nums[j]);
				int k = j + 1, l = n - 1;
				while (k < l) {
					int curr = nums[k] + nums[l];
					if (curr > target) {
						l--;
					} else if (curr < target) {
						k++;
					} else {
						vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
						while (k < l && nums[k] == temp[2]) {
							k++;
						}
						while (k < l && nums[l] == temp[3]) {
							l--;
						}
						ans.push_back(temp);
					}
				}
				while (j + 1 < n && nums[j + 1] == nums[j]) {
					j++;
				}
			}
			while (i + 1 < n && nums[i + 1] == nums[i]) {
				i++;
			}
		}
		return ans;
	}
};