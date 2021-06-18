class Solution {
	func minFlips(_ s: String) -> Int {
		let S = Array(s)
		var arr = [Int](repeating: 0, count: 2 * S.count)
		for i in arr.indices {
			let idx = Int(i)
			arr[i] = (idx % 2) ^ S[idx % S.count].toIntValue()
		}
		var (zeros, ones) = (0, 0)
		for i in S.indices {
			arr[i] == 0 ? (zeros += 1) : (ones += 1)
		}
		var (i, j, ans) = (0, S.count, S.count)
		while j < arr.count {
			ans = min(ans, zeros)
			ans = min(ans, ones)
			arr[i] == 0 ? (zeros -= 1) : (ones -= 1)
			i += 1
			arr[j] == 0 ? (zeros += 1) : (ones += 1)
			j += 1
		}
		return ans
	}
}

extension Character {
	func toIntValue() -> Int {
		return Int(String(self)) ?? 0
	}
}