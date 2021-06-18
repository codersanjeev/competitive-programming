
class Solution {
	func subsetXORSum(_ nums: [Int]) -> Int {
		var answer = 0
		for mask in 1..<(1 << nums.count) {
			var curr = 0
			for i in nums.indices {
				if (mask & (1 << i)) != 0 {
					curr ^= nums[i]
				}
			}
			answer += curr
		}
		return answer
	}
}
