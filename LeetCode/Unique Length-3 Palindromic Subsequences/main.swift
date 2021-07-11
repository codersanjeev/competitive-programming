class Solution {
	func countPalindromicSubsequence(_ S: String) -> Int {
		let s = Array(S)
		var index = [[Int]](repeating: [-1, -1], count: 26)
		for i in s.indices {
			let curr = s[i].intValue
			if index[curr][0] == -1 {
				index[curr][0] = i
			} else {
				index[curr][1] = i
			}
		}
		var ans = 0
		for i in 0 ..< 26 {
			var curr = Set<Character>()
			for j in stride(from: index[i][0] + 1, to: index[i][1], by: 1) {
				curr.insert(s[j])
			}
			ans += curr.count
		}
		return ans
	}
}

extension Character {
	var asciiValueNormalized: Int {
		return Int(self.asciiValue ?? 0)
	}
	
	var intValue: Int {
		return self.asciiValueNormalized - Character("a").asciiValueNormalized
	}
}