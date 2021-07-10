class Solution {
	private var dp = [Int]()
	private let mod = Int(1e9 + 7)
	
	private func numDecodingsHelper(_ s: [Character], _ index: Int) -> Int {
		if index == s.count { return 1 }
		if dp[index] != -1 { return dp[index] }
		var ans = 0
		if s[index] == Character("*") {
			ans = (ans + 9 * numDecodingsHelper(s, index + 1)) % mod
		} else if s[index] >= Character("1") && s[index] <= Character("9") {
			ans = (ans + numDecodingsHelper(s, index + 1)) % mod
		}
		if index + 1 < s.count {
			let (a, b) = (s[index], s[index + 1])
			if a == Character("2") && b == Character("*") {
				ans = (ans + 6 * numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("1") && b == Character("*") {
				ans = (ans + 9 * numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("*") && b == Character("*") {
				ans = (ans + 15 * numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("2") && b <= Character("6") {
				ans = (ans + numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("1") {
				ans = (ans + numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("*") && b <= Character("6") {
				ans = (ans + 2 * numDecodingsHelper(s, index + 2)) % mod
			} else if a == Character("*") {
				ans = (ans + numDecodingsHelper(s, index + 2)) % mod
			}
		}
		dp[index] = ans
		return ans
	}
	
	func numDecodings(_ s: String) -> Int {
		dp = [Int](repeating: -1, count: s.count)
		return numDecodingsHelper(Array(s), 0)
	}
}