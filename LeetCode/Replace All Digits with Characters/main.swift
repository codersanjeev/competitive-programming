
class Solution {
	
	private func shift(_ c: Character, _ x: Int) -> String {
		let alphabets = "abcdefghijklmnopqrstuvwxyz"
		let index = (alphabets.indexOf(c) + x) % alphabets.count
		return String(alphabets[index])
	}
	
	func replaceDigits(_ s: String) -> String {
		var ans = ""
		for i in stride(from: 1, to: s.count, by: 2) {
			ans += String(s[i - 1])
			ans += shift(s[i - 1], s[i].wholeNumberValue ?? 0)
		}
		if (s.count % 2 == 1) {
			ans += String(s.last ?? "a")
		}
		return ans
	}
}

extension String {
	
	subscript(offset: Int) -> Character {
		self[index(startIndex, offsetBy: offset)]
	}
	
	func indexOf(_ c: Character) -> Int {
		let index = self.index(of: c) ?? self.startIndex
		return self.distance(from: self.startIndex, to: index)
	}
}
