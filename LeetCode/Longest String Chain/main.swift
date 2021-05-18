
class Solution {
	func longestStrChain(_ w: [String]) -> Int {
		if w.count < 2 { return w.count }
		let words = w.sorted(by: { $0.count < $1.count })
		var dp = [Int](repeating: 1, count: words.count)
		for i in 1..<words.count {
			for j in 0..<i {
				if (words[j].isPredecessorOf(words[i])) {
					dp[i] = max(dp[i], 1 + dp[j])
				}
			}
		}
		return dp.max() ?? 0
	}
}

extension String {
	func isPredecessorOf(_ y: String) -> Bool {
		let x = self
		if y.count - x.count != 1 { return false }
		if y[1...] == x || y[0..<x.count] == x { return true }
		for i in 0..<y.count - 1 {
			let j = i + 1
			if y[0..<i] + y[j...] == x { return true }
		}
		return false
	}
	
	subscript(_ range: CountableRange<Int>) -> String {
		let start = index(startIndex, offsetBy: max(0, range.lowerBound))
		let end = index(start, offsetBy: min(self.count - range.lowerBound, range.upperBound - range.lowerBound))
		return String(self[start..<end])
	}
	
	subscript(_ range: CountablePartialRangeFrom<Int>) -> String {
		let start = index(startIndex, offsetBy: max(0, range.lowerBound))
		return String(self[start...])
	}
}
