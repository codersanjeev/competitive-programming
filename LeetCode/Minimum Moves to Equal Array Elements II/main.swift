class Solution {
	func minMoves2(_ arr: [Int]) -> Int {
		let nums = arr.sorted()
		var (ans, median) = (0, nums[nums.count / 2])
		nums.forEach { num in
			ans += abs(num - median)
		}
		return ans
	}
}
