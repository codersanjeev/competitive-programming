class Solution {
  public:
	bool canPartitionKSubsets(vector<int> &nums, int k) {
		if (k == 1) {
			return true;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0) {
			return false;
		}
		vector<bool> visited(nums.size(), false);
		return canPartitionKSubsetsUtil(nums, visited, 0, k, 0, sum / k);
	}

	bool canPartitionKSubsetsUtil(const vector<int> &nums, vector<bool> &visited, int index, int k, int currentSum, int targetSum) {
		if (k == 1) {
			return true;
		}
		if (currentSum == targetSum) {
			return canPartitionKSubsetsUtil(nums, visited, 0, k - 1, 0, targetSum);
		}
		if (currentSum > targetSum) {
			return false;
		}
		for (int i = index; i < nums.size(); i++) {
			if (visited[i] == false) {
				visited[i] = true;
				if (canPartitionKSubsetsUtil(nums, visited, i + 1, k, currentSum + nums[i], targetSum)) {
					return true;
				}
				visited[i] = false;
			}
		}
		return false;
	}

};