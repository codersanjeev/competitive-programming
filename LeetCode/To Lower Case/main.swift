class Solution {
	func toLowerCase(_ s: String) -> String {
		var ans = ""
		for ch in s {
			if ch >= "A" && ch <= "Z" {
				ans += ch.lowercased()
			} else {
                ans += String(ch)
            }
		}
		return ans
	}
}