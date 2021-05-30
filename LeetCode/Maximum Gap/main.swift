
class Solution {
	func maximumGap(_ nums: [Int]) -> Int {
		if nums.count < 2 { return 0 }
		let (mx, mn) = (nums.max()!, nums.min()!)
		let bucket = Double(mx - mn) / Double(nums.count - 1)
		var maxElement = [Int](repeating: Int.min, count: nums.count)
		var minElement = [Int](repeating: Int.max, count: nums.count)
		for i in nums.indices {
			let index = bucket == 0.0 ? 0 : Int(Double(nums[i] - mn) / bucket)
			maxElement[index] = max(maxElement[index], nums[i])
			minElement[index] = min(minElement[index], nums[i])
		}
		var (ans, previous) = (0, maxElement[0])
		for i in 1 ..< nums.count {
			if minElement[i] == Int.max { continue }
			ans = max(ans, minElement[i] - previous)
			previous = maxElement[i]
		}
		return ans
	}
}
