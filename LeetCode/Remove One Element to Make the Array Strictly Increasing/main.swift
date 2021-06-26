class Solution {
	func canBeIncreasing(_ nums: [Int]) -> Bool {
		for i in nums.indices {
			var (prev, found) = (-1, true)
			for j in nums.indices {
				if i != j {
					if nums[j] > prev {
						prev = nums[j]
					} else {
						found = false
					}
				}
			}
			if found { return true }
		}
		return false
	}
}