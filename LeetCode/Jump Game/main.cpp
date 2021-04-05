class Solution {
  public:
	bool canJump(vector<int> &nums) {
		int reach = 0, curr = 0;
		while (curr <= reach && curr < nums.size()) {
			reach = max(reach, curr + nums[curr]);
			curr++;
		}
		return reach >= nums.size() - 1;
	}
};