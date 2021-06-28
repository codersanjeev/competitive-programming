class Solution {
	func removeDuplicates(_ s: String) -> String {
		var st = [Character]()
		var good = false
		for ch in s {
			good = false
			while true {
				if let last = st.last, last == ch {
					good = true
					st.removeLast()
				} else { break }
			}
			if good { continue }
			st.append(ch)
		}
		var ans = ""
		while !st.isEmpty {
			ans += String(st.removeFirst())
		}
		return ans
	}
}