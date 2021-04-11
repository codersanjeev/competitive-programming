class Solution {
	func findTheWinner(_ n: Int, _ k: Int) -> Int {
        if (n == 1 && k == 1) {
            return 1
        }
		var ans = 0
		for i in 2...n {
			ans = (ans + k) % i
		}
		return ans + 1
	}
}
