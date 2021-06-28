class Solution {
	func maxProductDifference(_ arr: [Int]) -> Int {
		let nums = arr.sorted()
		let n = nums.count
		return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1])
	}
}