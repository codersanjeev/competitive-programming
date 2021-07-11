class Solution {
	func sumGame(_ z: String) -> Bool {
		let num = Array(z)
		let n = num.count
		var (x, y) = (0.0, 0.0)
		for i in num.indices {
			var a = 4.5
			if num[i] != Character("?") {
				a = num[i].doubleValue
			}
			if i < n / 2 {
				x += a
			} else {
				y += a
			}
		}
		return x != y
	}
}

extension Character {
	var doubleValue: Double {
		return Double(String(self)) ?? 0.0
	}
}