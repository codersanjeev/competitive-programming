class Solution {
	func wonderfulSubstrings(_ w: String) -> Int {
		let word = Array<Character>(w)
		var (ans, x) = (0, 0)
		var mp = [Int:Int]()
		mp[0] = 1
		for j in word.indices {
			x ^= 1 << word[j].intValue
			ans += (mp[x] ?? 0)
			for i in 0 ..< 10 {
				ans += mp[x ^ (1 << i)] ?? 0
			}
			mp[x] = (mp[x] ?? 0) + 1
		}
		return ans
	}
}

extension Character {
	private var asciiValueNormalized: Int {
		return Int(self.asciiValue ?? UInt8(0))
	}
	
	var intValue: Int {
		return self.asciiValueNormalized - Character("a").asciiValueNormalized
	}
}
