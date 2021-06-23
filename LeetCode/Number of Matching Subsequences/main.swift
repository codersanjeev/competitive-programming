class Solution {
	func numMatchingSubseq(_ S: String, _ words: [String]) -> Int {
		let s = Array(S)
		var index = [[Int]](repeating: [Int](repeating: s.count, count: 26), count: s.count + 1)
		for i in stride(from: s.count - 1, to: -1, by: -1) {
			for j in 0 ..< 26 {
				index[i][j] = index[i + 1][j]
			}
			index[i][s[i].intValue] = i
		}
		var ans = 0
		for word in words {
			var (curr, good) = (0, true)
			for ch in word {
				curr = index[curr][ch.intValue]
				if curr == s.count {
					good = false
					break
				}
                curr += 1
			}
			if good { ans += 1 }
		}
		return ans
	}
}

extension Character {
	private var asciiValueNormalized: Int {
		return Int(self.asciiValue ?? UInt8(0))
	}
	
	var intValue: Int {
		return self.asciiValueNormalized - Character("a").asciiValueNormalized
	}
}