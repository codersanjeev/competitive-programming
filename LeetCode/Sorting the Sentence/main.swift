
struct Word {
	var word: String
	var index: Int
}

class Solution {
	func sortSentence(_ s: String) -> String {
		var arr = [Word]()
		s.split(separator: " ").forEach { w in
            var word = String(w)
			let index = Int(String(word.last ?? "0")) ?? 0
			word.removeLast()
			arr.append(Word(word: word, index: index))
		}
		arr.sort { $0.index < $1.index }
		var answer = ""
		arr.forEach { word in
			answer += word.word
			answer += " "
		}
		answer.removeLast()
		return answer
	}
}
