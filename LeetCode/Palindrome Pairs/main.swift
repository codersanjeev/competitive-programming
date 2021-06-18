class Solution {
	func palindromePairs(_ w: [String]) -> [[Int]] {
		let words = w.compactMap({ Array<Character>($0) })
		var ans = [[Int]]()
		var mp = [[Character]:Int]()
		for (wordIndex, word) in words.enumerated() {
			mp[word] = wordIndex
		}
		for (wordIndex, word) in words.enumerated() {
			for len in 0 ... word.count {
				let prefix = Array<Character>(word[0..<len])
				let suffix = Array<Character>(word[len...])
				if prefix == prefix.reversed() {
					let suffixReversed = Array<Character>(suffix.reversed())
					if let suffixReversedIndex = mp[suffixReversed], 
                        suffixReversedIndex != wordIndex {
						ans.append([suffixReversedIndex, wordIndex])
					}
				}
				if suffix == suffix.reversed() {
					let prefixReversed = Array<Character>(prefix.reversed())
					if let prefixReversedIndex = mp[prefixReversed], 
                        prefixReversedIndex != wordIndex, !suffix.isEmpty {
						ans.append([wordIndex, prefixReversedIndex])
					}
				}
			}
		}
		return ans
	}
}