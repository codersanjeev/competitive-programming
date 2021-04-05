class Solution {
  public:
	int findMin(vector<int> &nums) {
		// 3 4 5 1 2
		// nums[i] > nums[i + 1]
		int lo = 0, hi = nums.size() - 1;
		if (hi - lo == 0) {
			return nums[0];
		} else if (nums[hi] > nums[lo]) {
			return nums[lo];
		}
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
				return nums[mid + 1];
			} else if (nums[lo] < nums[mid]) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return -1;
	}
};