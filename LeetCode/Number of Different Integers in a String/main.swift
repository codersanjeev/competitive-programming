extension Sequence where Iterator.Element: Hashable {
	func unique() -> [Iterator.Element] {
		var seen: Set<Iterator.Element> = []
		return filter { seen.insert($0).inserted }
	}
}

class Solution {
	func numDifferentIntegers(_ word: String) -> Int {
		return word.replacingOccurrences(of: "[a-z]", with: " ", options: .regularExpression, range: nil).split(separator: " ").map({ $0.replacingOccurrences(of: "^0+", with: "", options: .regularExpression, range: nil) }).unique().count
	}
}
