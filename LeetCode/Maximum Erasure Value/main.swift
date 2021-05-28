class Solution {
	func maximumUniqueSubarray(_ nums: [Int]) -> Int {
		var (i, j, curr, ans) = (0, 0, 0, 0)
		var seen = [Bool](repeating: false, count: nums.max()! + 1)
		while j < nums.count {
			while seen[nums[j]] == true {
				seen[nums[i]] = false
				curr -= nums[i]
				i += 1
			}
			seen[nums[j]] = true
			curr += nums[j]
			ans = max(ans, curr)
			j += 1
		}
		return ans
	}
}