auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int searchInsert(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1, ans = -1;
		if (target < nums[0]) {
			return 0;
		} else if (target > nums.back()) {
			return nums.size();
		}
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] >= target) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return ans;
	}
};