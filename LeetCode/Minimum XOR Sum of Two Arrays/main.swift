class Solution {
	func minPairSum(_ nums: [Int]) -> Int {
		let arr = nums.sorted()
		var (i, j, ans) = (0, arr.count - 1, 0)
		while i < j {
			ans = max(ans, arr[i] + arr[j])
            i += 1
            j -= 1
		}
		return ans
	}
}
