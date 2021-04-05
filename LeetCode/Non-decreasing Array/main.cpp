class Solution {
  public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() == 1)
			return true;
		int posi = -1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1] && posi != -1)
				return false;
			if (nums[i] < nums[i - 1])
				posi = i;
		}
		if (posi == -1 || posi == 1 || posi == nums.size() - 1)
			return true;
		return (nums[posi - 1] <= nums[posi + 1]) || (nums[posi - 2] <= nums[posi]);
	}
};