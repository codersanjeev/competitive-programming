class Solution {
	func findPeakElement(_ nums: [Int]) -> Int {
		var (lo, hi, ans) = (0, nums.count - 1, nums.count - 1)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if mid + 1 < nums.count && nums[mid] > nums[mid + 1] {
				ans = mid
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		}
		return ans
	}
}