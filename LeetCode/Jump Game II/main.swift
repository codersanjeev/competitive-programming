class Solution {
	func jump(_ nums: [Int]) -> Int {
		var ans = 0, curr = 0, reach = 0
		for i in nums.indices {
			if (i == nums.count - 1) {
				break
			}
			reach = max(reach, i + nums[i])
			if (i == curr) {
				ans += 1
				curr = reach
			}
		}
		return ans
	}
}