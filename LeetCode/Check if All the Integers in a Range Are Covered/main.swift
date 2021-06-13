class Solution {
	func isCovered(_ ranges: [[Int]], _ left: Int, _ right: Int) -> Bool {
		var visited = [Bool](repeating: false, count: 51)
		for range in ranges {
			for i in range[0] ... range[1] {
				visited[i] = true
			}
		}
		for i in left ... right {
			if visited[i] == false {
				return false
			}
		}
		return true
	}
}