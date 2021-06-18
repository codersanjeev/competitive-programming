class Solution {
	func sumBase(_ n: Int, _ k: Int) -> Int {
		return String(n, radix: k).compactMap{ $0.wholeNumberValue }.reduce(0, +)
	}
}
