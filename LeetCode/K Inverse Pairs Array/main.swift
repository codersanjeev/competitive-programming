class Solution {
	
	private var dp = [[Int]](
        repeating: [Int](
            repeating: 0, count: 1001
        ), count: 1001)
	private let mod = 1000000007
	
	func kInversePairs(_ n: Int, _ k: Int) -> Int {
		let pos = (n * (n - 1)) >> 1
		if k < 0 || k > pos { return 0 }
		if k == 0 || k == pos { return 1 }
		if dp[n][k] != 0 { return dp[n][k] }
		let ans = kInversePairs(n, k - 1) + 
                  kInversePairs(n - 1, k) - 
                  kInversePairs(n - 1, k - n) + mod
		dp[n][k] = ans % mod
		return dp[n][k]
	}
}
