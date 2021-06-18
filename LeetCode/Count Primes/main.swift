class Solution {
	func countPrimes(_ n: Int) -> Int {
		if (n < 2) {
			return 0
		}
		var prime = [Bool](repeating: true, count: n)
		prime[0] = false
		prime[1] = false
		for i in 2..<n {
			if (prime[i]) {
				var j = 2 * i
				while (j < n) {
					prime[j] = false
					j += i
				}
			}
		}
		var ans = 0
		prime.forEach {
			if ($0) {
				ans += 1
			}
		}
		return ans
	}
}
