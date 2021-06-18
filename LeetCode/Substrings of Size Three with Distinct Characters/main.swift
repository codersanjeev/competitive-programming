class Solution {
	func countGoodSubstrings(_ s: String) -> Int {
		var ans = 0
        if s.count < 3 { return ans }
		for i in 0 ..< s.count - 2 {
			var temp = Set<String>()
			for j in 0 ..< 3 {
				temp.insert(s[i + j])
			}
			if temp.count == 3 {
				ans += 1
			}
		}
		return ans
	}
}

extension String {
    subscript(i: Int) -> String {
        return String(self[index(startIndex, offsetBy: i)])
    }
}
