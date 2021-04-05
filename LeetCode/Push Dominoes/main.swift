
class Solution {
	func pushDominoes(_ dominoes: String) -> String {
		var ans = dominoes
		while true {
			let newDominoes = ans.replacingOccurrences(of: "R.L", with: "|").replacingOccurrences(of: ".L", with: "LL").replacingOccurrences(of: "R.", with: "RR").replacingOccurrences(of: "|", with: "R.L")
			if ans == newDominoes {
				break
			} else {
				ans = newDominoes
			}
		}
		return ans
	}
}
