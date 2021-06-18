
class Solution {
	func maxArea(_ h: Int, _ w: Int, _ H: [Int], _ V: [Int]) -> Int {
		var (horizontal, vertical) = (H, V)
		horizontal += [0, h]
		vertical += [0, w]
		horizontal.sort()
		vertical.sort()
		var (maxHorizontalDiff, maxVerticalDiff) = (0, 0)
		for i in 1 ..< horizontal.count {
			maxHorizontalDiff = max(maxHorizontalDiff, horizontal[i] - horizontal[i - 1])
		}
		for i in 1 ..< vertical.count {
			maxVerticalDiff = max(maxVerticalDiff, vertical[i] - vertical[i - 1])
		}
		return (maxHorizontalDiff * maxVerticalDiff) % 1000000007
	}
}
