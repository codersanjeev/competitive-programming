class Solution {
	func findDuplicate(_ paths: [String]) -> [[String]] {
		var mp = [Int: [String]]()
		paths.forEach {
			let s = $0.split(separator: " ")
			for i in 1..<s.count {
				let fileParts = s[i].split(separator: "(")
				mp[fileParts[1].hashValue, default: []].append("\(s.first!)/\(fileParts.first!)")
			}
		}
		return mp.filter{ $0.1.count > 1 }.map{ $0.1 }
	}
}
