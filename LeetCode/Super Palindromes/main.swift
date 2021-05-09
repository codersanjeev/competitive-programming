
class Solution {
	func superpalindromesInRange(_ left: String, _ right: String) -> Int {
		let L = Int64(left) ?? Int64(0)
		let R = Int64(right) ?? Int64(0)
		let all = generateAllPalindromes()
		var ans = 0
		all.forEach { ele in
			if (ele <= Int(1e9)) {
				let x = Int64(ele * ele)
				if (x >= L && x <= R && palindrome(x)) {
					ans += 1
				}
			}
		}
		return ans
	}
	
	private func generateAllPalindromes() -> [Int] {
		var ans = [Int]()
		for i in 1...9 {
			ans.append(Int(i))
		}
		for i in 1...10000 {
			let s = String(i)
			let t = s.reversed()
			ans.append(Int(s + t) ?? 0)
			for ch in 0...9 {
				let temp = s + String(ch) + t
				ans.append(Int(temp) ?? 0)
			}
		}
		return ans
	}
	
	private func palindrome(_ x: Int64) -> Bool {
		var a = x, b = Int64(0)
		while (a > 0) {
			b = b * 10 + a % 10
			a /= 10
		}
		return x == b
	}
}
