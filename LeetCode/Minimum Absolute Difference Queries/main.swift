class Solution {
	func minDifference(_ nums: [Int], _ queries: [[Int]]) -> [Int] {
		var prefix = [[Int]](repeating: [Int](repeating: 0, count: 101), count: nums.count)
		var freq = [Int](repeating: 0, count: 101)
		for i in nums.indices {
			freq[nums[i]] += 1
			for j in freq.indices {
				prefix[i][j] = freq[j]
			}
		}
		var ans = [Int]()
		for query in queries {
			let (l, r) = (query[0], query[1])
			var arr = [Int]()
			for j in freq.indices {
				if prefix[r][j] > (l - 1 >= 0 ? prefix[l - 1][j] : 0) {
					arr.append(j)
				}
			}
			var curr = Int.max
			for i in 1 ..< arr.count {
				curr = min(curr, arr[i] - arr[i - 1])
			}
			ans.append(curr == Int.max ? -1 : curr)
		}
		return ans
	}
}