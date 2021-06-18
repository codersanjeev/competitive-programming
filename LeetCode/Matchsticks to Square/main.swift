class Solution {
	private var squareSide = 0
	
	private func makesquareRecursive(_ matchsticks: [Int], _ index: Int, _ square: inout [Int]) -> Bool {
		if index == matchsticks.count { return Set(square).count == 1 }
		for i in 0 ..< 4 {
			square[i] += matchsticks[index]
			if square[i] <= self.squareSide && makesquareRecursive(matchsticks, index + 1, &square) {
				return true
			}
			square[i] -= matchsticks[index]
		}
		return false
	}
	
	func makesquare(_ matchsticks: [Int]) -> Bool {
		let sum = matchsticks.reduce(0, +)
		if sum % 4 != 0 { return false }
		self.squareSide = sum / 4
		var square = [Int](repeating: 0, count: 4)
		return makesquareRecursive(matchsticks.sorted(by: >), 0, &square)
	}
}
