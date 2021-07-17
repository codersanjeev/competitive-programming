class Solution {
	func threeEqualParts(_ arr: [Int]) -> [Int] {
		var ones = arr.filter({ $0 == 1 }).count
		if ones % 3 != 0 { return [-1, -1] }
		if ones == 0 { return [0, arr.count - 1] }
		ones /= 3
		var (curr, x, y, z) = (0, 0, 0, 0)
		for i in arr.indices {
			if arr[i] == 1 {
				if curr % ones == 0 {
					let temp = curr / ones
					if temp == 0 {
						x = i
					} else if temp == 1 {
						y = i
					} else {
						z = i
					}
				}
				curr += 1
			}
		}
		while z != arr.count {
			if arr[x] != arr[y] || arr[y] != arr[z] {
				return [-1, -1]
			}
			x += 1; y += 1; z += 1
		}
		return [x - 1, y]
	}
}