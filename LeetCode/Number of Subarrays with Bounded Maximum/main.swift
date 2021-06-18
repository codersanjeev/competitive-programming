class Solution {
	private func solve(_ nums: [Int], _ maxValue: Int) -> Int {
		var (ans, curr) = (0, 0)
		for ele in nums {
			curr = ele <= maxValue ? curr + 1 : 0
			ans += curr
		}
		return ans
	}
	
	func numSubarrayBoundedMax(_ nums: [Int], _ left: Int, _ right: Int) -> Int {
		return solve(nums, right) - solve(nums, left - 1)
	}
}
