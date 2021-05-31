class Trie {
	public var children = [Character : Trie]()
	public var suggestion = [String]()
}

class Solution {
	func suggestedProducts(_ arr: [String], _ word: String) -> [[String]] {
		var products = arr.sorted()
		var trie: Trie? = Trie()
		products.forEach { product in
			var node = trie
			product.forEach { ch in
				if !node?.children.contains(where: { $0.key == ch }) {
					node?.children[ch] = Trie()
				}
				node = node?.children[ch] ?? Trie()
				if (node?.suggestion.count ?? 3) < 3 {
					node?.suggestion.append(product)
				}
			}
		}
		var answer = [[String]]()
		word.forEach { ch in
            trie = trie?.children[ch]
			if trie != nil {
				answer.append(trie?.suggestion ?? [])
			} else {
				answer.append([])
			}
		}
		return answer
	}
}
