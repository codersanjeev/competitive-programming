
class WordFilter {
	
	private var mp = [String : Int]()
	
	init(_ words: [String]) {
		for i in 0..<words.count {
			var prefix = [String]()
			var suffix = [String]()
			for j in 0...words[i].count {
				prefix.append(String(words[i].prefix(j)))
				suffix.append(String(words[i].suffix(words[i].count - j)))
			}
			prefix.forEach { p in
				suffix.forEach { s in
					let key = p + "$" + s
					mp[key] = max(mp[key] ?? 0, i)
				}
			}
		}
	}
	
	func f(_ prefix: String, _ suffix: String) -> Int {
		let key = prefix + "$" + suffix
		return mp[key] ?? -1
	}
}
