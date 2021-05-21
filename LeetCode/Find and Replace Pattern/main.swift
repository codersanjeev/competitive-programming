class Solution {
	private func isSame(_ word: String, _ pattern: String) -> Bool {
		var (wordMap, patternMap) = ([Character:Character](), [Character:Character]())
		for i in word.indices {
			let (w, p) = (word[i], pattern[i])
			if !wordMap.contains(where: { $0.key == w }) {
				wordMap[w] = p
			}
			if !patternMap.contains(where: { $0.key == p }) {
				patternMap[p] = w
			}
			if wordMap[w] != p || patternMap[p] != w {
				return false
			}
 		}
		return true
	}
	
	func findAndReplacePattern(_ words: [String], _ pattern: String) -> [String] {
		var ans = [String]()
		words.forEach { word in
			if (isSame(word, pattern)) {
				ans.append(word)
			}
		}
		return ans
	}
}
