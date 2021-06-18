class Solution {
	func arraySign(_ nums: [Int]) -> Int {
		var negativeCount = 0
		var hasZeros = false
		nums.forEach { num in
			if (num == 0) {
				hasZeros = true
			} else if (num < 0) {
				negativeCount += 1
			}
		}
		if (hasZeros) {
			return 0
		} else {
			return (negativeCount % 2 == 0 ? 1 : -1)
		}
	}
}
