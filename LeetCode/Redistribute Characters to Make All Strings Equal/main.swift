class Solution {
	func makeEqual(_ words: [String]) -> Bool {
		var freq = [Int](repeating: 0, count: 26)
		for word in words {
			for ch in word {
				freq[ch.charToIndex] += 1
			}
		}
		for ele in freq {
			if ele % words.count != 0 {
				return false
			}
		}
		return true
	}
}

extension Character {
	var charToIndex: Int {
		return Int(self.asciiValue ?? 0) - Int(Character("a").asciiValue ?? 0)
	}
}
