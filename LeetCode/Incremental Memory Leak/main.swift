
class Solution {
	func memLeak(_ memory1: Int, _ memory2: Int) -> [Int] {
		var (x, y, t) = (memory1, memory2, 1)
		while (true) {
			if (x >= y) {
				if (t > x) {
					return [t, x, y]
				}
				x -= t
			} else if (x < y) {
				if (t > y) {
					return [t, x, y]
				}
				y -= t
			}
			t += 1
		}
		return []
	}
}
