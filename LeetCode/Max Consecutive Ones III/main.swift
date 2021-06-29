class Solution {
	func longestOnes(_ nums: [Int], _ k: Int) -> Int {
		var (lo, hi, K) = (0, 0, k)
		while hi < nums.count {
			if nums[hi] == 0 {
				K -= 1
			}
			if K < 0 {
				if nums[lo] == 0 {
					K += 1
				}
				lo += 1
			}
			hi += 1
		}
		return hi - lo
	}
}