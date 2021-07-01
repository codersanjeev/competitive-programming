class Solution {
	private func grayCodeRecursive(_ n: Int) -> [String] {
		if n == 1 { return ["0", "1"] }
		let previousCodes = grayCodeRecursive(n - 1)
		var ans = [String]()
		for ele in previousCodes {
			ans.append("0" + ele)
		}
		for ele in previousCodes.reversed() {
			ans.append("1" + ele)
		}
		return ans
	}
	
	func grayCode(_ n: Int) -> [Int] {
		let grayCodes = grayCodeRecursive(n)
		return grayCodes.map{ $0.toDecimal }
	}
}

extension String {
	var toDecimal: Int {
		var ans = 0
		for (i, ch) in self.enumerated() {
			if ch == Character("1") {
				ans |= (1 << i)
			}
		}
		return ans
	}
}