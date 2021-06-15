class Solution {
	func maximumUnits(_ b: [[Int]], _ t: Int) -> Int {
		var boxTypes = b.sorted{ $0[1] > $1[1] }
		var (ans, truckSize) = (0, t)
		for index in boxTypes.indices {
			if truckSize <= 0 { break }
			let curr = min(truckSize, boxTypes[index][0])
			ans += boxTypes[index][1] * curr
			boxTypes[index][0] -= curr
			truckSize -= curr
		}
		return ans
	}
}
