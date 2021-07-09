class Solution {
	func findLength(_ A: [Int], _ B: [Int]) -> Int {
		let (n, m) = (A.count, B.count)
		var dp = [[Int]](repeating: [Int](repeating: 0, count: m + 1), count: n + 1)
		for i in stride(from: n - 1, to: -1, by: -1) {
			for j in stride(from: m - 1, to: -1, by: -1) {
				if A[i] == B[j] {
					dp[i][j] = dp[i + 1][j + 1] + 1
				}
			}
		}
		var ans = 0
		for row in dp {
			for ele in row {
				ans = max(ans, ele)
			}
		}
		return ans
	}
}