class Solution {
	func customSortString(_ order: String, _ str: String) -> String {
		var orderMap = [Character : Int]()
		var counter = 0
		for ch in order {
			orderMap[ch] = counter + 1
			counter += 1
		}
		return String(str.sorted(by: {
			(orderMap[$0] ?? 0) < (orderMap[$1] ?? 0)
		}))
	}
}