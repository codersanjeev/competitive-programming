class Solution {
	func removeOccurrences(_ s: String, _ part: String) -> String {
		var ans = s
		while true {
			if let it = ans.range(of: part) {
				ans.removeSubrange(it)
			} else {
				break
			}
		}
		return ans
	}
}