class Solution {
	func isIsomorphic(_ S: String, _ T: String) -> Bool {
		let (s, t) = (Array(S), Array(T))
		var a = [Int](repeating: 0, count: 256)
		var b = [Int](repeating: 0, count: 256)
		for i in s.indices {
			let x = Int(s[i].asciiValue ?? 0)
			let y = Int(t[i].asciiValue ?? 0)
			if a[x] != b[y] {
				return false
			}
			a[x] = i + 1
			b[y] = i + 1
		}
		return true
	}
}