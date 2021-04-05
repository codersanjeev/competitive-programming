class Solution {
    func countCharacters(_ words: [String], _ chars: String) -> Int {
		var ans = 0
        var mp = [Character: Int]()
        var i = 0
        for ch in "abcdefghijklmnopqrstuvwxyz" {
            mp[ch] = i
            i += 1
        }
		var freq = Array<Int>(repeating: 0, count: 26)
		chars.forEach { ch in 
			freq[mp[ch] ?? 0] += 1
		}
		words.forEach { word in 
			var cnt = Array<Int>(repeating: 0, count: 26)
			word.forEach { ch in
				cnt[mp[ch] ?? 0] += 1
			}
			var good = true
			for i in 0..<26 {
				if (cnt[i] > freq[i]) {
					good = false
					break
				}
			}
			if (good) {
				ans += word.count
			}
		}
		return ans        
    }
}
