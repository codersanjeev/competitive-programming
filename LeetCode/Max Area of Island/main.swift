class Solution {
	
	private let dx = [0, 0, 1, -1]
	private let dy = [1, -1, 0, 0]
	
	private func dfs(_ grid: inout [[Int]], _ i: Int, _ j: Int) -> Int {
		if i < 0 || j < 0 || i >= grid.count || j >= grid[0].count || grid[i][j] != 1 {
			return 0
		}
		grid[i][j] = -1
		var ans = 1
		for k in 0 ..< 4 {
			ans += dfs(&grid, i + dx[k], j + dy[k])
		}
		return ans
	}
	
	func maxAreaOfIsland(_ g: [[Int]]) -> Int {
		var (ans, grid) = (0, g)
		for i in grid.indices {
			for j in grid[0].indices {
				if grid[i][j] == 1 {
					ans = max(ans, dfs(&grid, i, j))
				}
			}
		}
		return ans
	}
}
