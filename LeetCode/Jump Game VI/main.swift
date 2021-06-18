class Solution {
	func maxResult(_ arr: [Int], _ k: Int) -> Int {
		var (q, nums) = ([Int](), arr)
		for i in nums.indices {
			nums[i] += q.isEmpty ? 0 : nums[q.first ?? 0]
			while !q.isEmpty && nums[q.last ?? 0] < nums[i] {
				q.removeLast()
			}
			q.append(i)
			while !q.isEmpty && i - (q.first ?? 0) + 1 > k {
				q.removeFirst()
			}
		}
		return nums.last ?? 0
	}
}