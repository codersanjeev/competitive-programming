class Solution {
	func maxProduct(_ words: [String]) -> Int {
		var arr = [Int](repeating: 0, count: words.count)
		var ans = 0
		for i in words.indices {
			for j in words[i].indices {
				arr[i] = arr[i] | (1 << words[i][j].asciiValueNormalized)
			}
		}
		for i in words.indices {
			for j in i + 1 ..< words.count {
				if (arr[i] & arr[j] == 0) {
					ans = max(ans, words[i].count * words[j].count)
				}
			}
		}
		return ans
	}
}

extension Character {
	var asciiValueNormalized: Int {
		return Int(self.asciiValue! - Character("a").asciiValue!)
	}
}
