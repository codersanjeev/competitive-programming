class Solution {
	private var grid1 = [[Int]]()
	private var grid2 = [[Int]]()
	private let dx = [0, 0, 1, -1]
	private let dy = [1, -1, 0, 0]
	private var n = 0
	private var m = 0
	
	private func dfs(_ i: Int, _ j: Int) -> Int {
		if i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0 {
			return -1
		}
		if grid1[i][j] == 0 {
			return 0
		}
		grid2[i][j] = 0
		var res = 1
		for k in dx.indices {
			if dfs(i + dx[k], j + dy[k]) == 0 {
				res = 0
			}
		}
		return res
	}
	
	func countSubIslands(_ grid1: [[Int]], _ grid2: [[Int]]) -> Int {
		self.grid1 = grid1
		self.grid2 = grid2
		self.n = grid2.count
		self.m = grid2[0].count
		var ans = 0
		for i in grid2.indices {
			for j in grid2[0].indices {
				if dfs(i, j) == 1 {
					ans += 1
				}
			}
		}
		return ans
	}
}
