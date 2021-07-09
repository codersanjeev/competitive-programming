class Solution {
	func lengthOfLIS(_ nums: [Int]) -> Int {
		let n = nums.count
		var dp = [Int](repeating: 1, count: n)
		for i in 1 ..< n {
			for j in 0 ..< i {
				if nums[i] > nums[j] {
					dp[i] = max(dp[i], 1 + dp[j])
				}
			}
		}
		return dp.max() ?? 1
	}
}