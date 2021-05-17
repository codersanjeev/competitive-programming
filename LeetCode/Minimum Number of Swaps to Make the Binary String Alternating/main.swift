
class Solution {
	private func fill(_ S: Array<Character>, _ ch: Character) -> Int {
		var answer = 0
		for i in stride(from: 0, to: S.count, by: 2) {
			if (S[i] != ch) {
				answer += 1
			}
		}
		return answer
	}
	
	func minSwaps(_ s: String) -> Int {
		let S = Array(s)
		let (N, zeros, ones) = (S.count, S.filter({ $0 == "0" }).count, S.filter({ $0 == "1" }).count)
		if (abs(ones - zeros) > 1) {
			return -1
		}
		let (x, y) = (fill(S, "1"), fill(S, "0"))
		if ones > zeros {
			return x
		} else if ones < zeros {
			return y
		} else {
			return min(x, y)
		}
	}
}
