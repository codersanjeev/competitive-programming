class Solution {
	func isInterleave(_ s1: String, _ s2: String, _ s3: String) -> Bool {
		if s1.count + s2.count != s3.count { return false }
        if s1.isEmpty && s2.isEmpty && s3.isEmpty { return true }
        if s1.isEmpty { return s2 == s3 }
		if s2.isEmpty { return s1 == s3 }
		if s3.isEmpty { return s1.isEmpty && s2.isEmpty }
		var (x, y, z) = (Array(s1), Array(s2), Array(s3))
		var dp = [[Bool]](repeating: [Bool](repeating: false, count: y.count + 1), count: x.count + 1)
		dp[0][0] = true
		for i in 1 ... x.count {
			dp[i][0] = dp[i - 1][0] && (x[i - 1] == z[i - 1])
		}
		for j in 1 ... y.count {
			dp[0][j] = dp[0][j - 1] && (y[j - 1] == z[j - 1])
		}
		for i in 1 ... x.count {
			for j in 1 ... y.count {
				dp[i][j] = (dp[i - 1][j] && x[i - 1] == z[i + j - 1]) 
                || (dp[i][j - 1] && y[j - 1] == z[i + j - 1])
			}
		}
		return dp[x.count][y.count]
	}
}
