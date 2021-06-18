class Solution {
	private func count(_ s: String, _ ch: Character) -> Int {
		let S = Array(s)
		var dp = [Int](repeating: 0, count: s.count)
		if S[0] == ch {
			dp[0] = 1
		}
		for i in 1 ..< s.count {
			if S[i] == ch {
				dp[i] = S[i] == S[i - 1] ? dp[i - 1] + 1 : 1
			}
		}
		return dp.max() ?? 0
	}
	
	func checkZeroOnes(_ s: String) -> Bool {
		return count(s, "1") > count(s, "0")
	}
}
