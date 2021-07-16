class Solution {
	func binarySearch(_ arr: [Int], _ i: Int, _ target: Int) -> Int {
		var (lo, hi, ans) = (i, arr.count - 1, 0)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if arr[mid] < target {
				ans = mid + 1 - i
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		return ans
	}
	
	func triangleNumber(_ arr: [Int]) -> Int {
		let nums = arr.sorted()
		var ans = 0
		for i in nums.indices {
			for j in i + 1 ..< nums.count {
				ans += binarySearch(nums, j + 1, nums[i] + nums[j])
			}
		}
		return ans
	}
}