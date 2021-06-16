class Solution {
	private var ans = [String]()
	
	private func generateParenthesisRecursive(_ n: Int, _ l: Int, _ r: Int, _ s: String) {
		if l == n && r == n {
			ans.append(s)
			return
		}
		if l < n {
			generateParenthesisRecursive(n, l + 1, r, s + "(")
		}
		if r < l {
			generateParenthesisRecursive(n, l, r + 1, s + ")")
		}
	}
	
	func generateParenthesis(_ n: Int) -> [String] {
		generateParenthesisRecursive(n, 0, 0, "")
		return ans
	}
}