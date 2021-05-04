class Solution {
	func checkPossibility(_ arr: [Int]) -> Bool {
		var nums = arr
		var changed = false
		var index = 1
		while (index < nums.count) {
			if (nums[index] < nums[index - 1]) {
				if (changed) {
					return false
				}
				changed = true
				if (index - 2 < 0 || nums[index - 2] <= nums[index]) {
					nums[index - 1] = nums[index]
				} else {
					nums[index] = nums[index - 1]
				}
			}
			index += 1
		}
		return true
	}
}