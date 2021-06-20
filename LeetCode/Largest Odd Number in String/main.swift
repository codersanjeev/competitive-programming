class Solution {
	func largestOddNumber(_ n: String) -> String {
		let num = Array<Character>(n)
		var index = num.count - 1
		while index >= 0 {
			if num[index].intValue % 2 == 1 { break }
			index -= 1
		}
        if index < 0 {
            return ""
        } else if index == 0 {
		    return String(num[0])
        } else {
            return String(num[0...index])
        }
	}
}

extension Character {
	private var nonNullAsciiValue: Int {
		return Int(self.asciiValue ?? UInt8(0))
	}
	
	var intValue: Int {
		return self.nonNullAsciiValue - Character("0").nonNullAsciiValue
	}
}