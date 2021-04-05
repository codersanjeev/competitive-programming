class Solution {
    func commonChars(_ A: [String]) -> [String] {
    	var freq = Array<Int>(repeating: Int.max, count: 26)
    	A.forEach { word in 
    		var cnt = Array<Int>(repeating: 0, count: 26)
    		word.forEach { ch in 
    			cnt[ch.toInt()] += 1
    		}
    		for i in 0..<26 {
    			freq[i] = min(freq[i], cnt[i])
    		}
    	}
    	var ans = [String]()
    	for i in 0..<26 {
    		while (freq[i] > 0) {
    			ans.append(i.toCharString())
    			freq[i] -= 1
    		}
    	}
    	return ans
    }
}

extension Character {
    func toInt() -> Int {
        var s = "abcdefghijklmnopqrstuvwxyz"
        var ans = 0
        for i in s {
            if (i == self) {
                return ans
            }
            ans += 1
        }
        return ans
    }
}

extension Int {
    func toCharString() -> String {
        var s = Array("abcdefghijklmnopqrstuvwxyz")
        return String(s[self])
    }
}
