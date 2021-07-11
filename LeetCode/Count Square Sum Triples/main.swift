class Solution {
	func countTriples(_ n: Int) -> Int {
		var ans = 0
		for a in 1 ... n {
			for b in 1 ... n {
				for c in 1 ... n {
					if a * a + b * b == c * c {
						ans += 1
					}
				}
			}
		}
		return ans
	}
}