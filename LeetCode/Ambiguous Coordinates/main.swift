class Solution {
	func ambiguousCoordinates(_ s: String) -> [String] {
		var S = Array(s)
		S.removeFirst()
		S.removeLast()
		var answer = [String]()
		for i in 1..<S.count {
			let left = generateNumbers(String(S[0..<i]))
			let right = generateNumbers(String(S[i..<S.count]))
			for l in left {
				for r in right {
					answer.append("(" + l + ", " + r + ")")
				}
			}
		}
		return answer
	}
	
	private func generateNumbers(_ S: String) -> [String] {
		var s = Array(S)
		var answer = [String]()
		if S.first == "0" && S.last == "0" {
			if S.count == 1 {
				answer.append(S)
			}
			return answer
		}
		if S.first == "0" {
			answer.append("0." + String(s[1..<s.count]))
			return answer
		} else if S.last == "0" {
			answer.append(String(s))
			return answer
		} else {
			answer.append(S)
			for i in 1..<s.count {
				let num = String(s[0..<i]) + "." + String(s[i..<s.count])
				answer.append(num)
			}
			return answer
		}
	}
}
