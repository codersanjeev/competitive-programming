class Solution {
	func candy(_ ratings: [Int]) -> Int {
		var ans = [Int](repeating: 1, count: ratings.count)
		for i in 1 ..< ratings.count {
			if ratings[i - 1] < ratings[i] {
				ans[i] = 1 + ans[i - 1]
			}
		}
		for i in stride(from: ratings.count - 1, to: 0, by: -1) {
			if ratings[i - 1] > ratings[i] {
				ans[i - 1] = max(ans[i - 1], 1 + ans[i])
			}
		}
		return ans.reduce(0, +)
	}
}