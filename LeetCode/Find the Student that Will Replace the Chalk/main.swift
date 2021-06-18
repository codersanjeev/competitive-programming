class Solution {
	func chalkReplacer(_ chalk: [Int], _ k: Int) -> Int {
		var rem = k % chalk.reduce(0, +)
		for i in chalk.indices {
			if chalk[i] > rem {
				return i
			}
			rem -= chalk[i]
		}
		return 0
	}
}
