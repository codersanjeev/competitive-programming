class Solution {
	func rotateGrid(_ g: [[Int]], _ k: Int) -> [[Int]] {
		var grid = g
		var (top, left, bottom, right) = (0, 0, grid.count - 1, grid[0].count - 1)
		while top < bottom && left < right {
			var K = k % (2 * (bottom - top + 1) + 2 * (right - left + 1) - 4)
			while K > 0 {
				let ele = grid[top][left]
				for j in left ..< right {
					grid[top][j] = grid[top][j + 1]
				}
				for i in top ..< bottom {
					grid[i][right] = grid[i + 1][right]
				}
				for j in stride(from: right, to: left, by: -1) {
					grid[bottom][j] = grid[bottom][j - 1]
				}
				for i in stride(from: bottom, to: top, by: -1) {
					grid[i][left] = grid[i - 1][left]
				}
				grid[top + 1][left] = ele
				K -= 1
			}
			top += 1
			left += 1
			bottom -= 1
			right -= 1
		}
		return grid
	}
}