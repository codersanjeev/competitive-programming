class Solution {
	func reductionOperations(_ nums: [Int]) -> Int {
		let arr = nums.sorted()
		var (ans, cnt) = (0, 0)
		for i in 1 ..< arr.count {
			if arr[i] != arr[i - 1] { cnt += 1 }
			ans += cnt
		}
		return ans
	}
}