class Solution {
	private var grid = [[Int]]()
	private let dx = [0, 0, 1, -1]
	private let dy = [1, -1, 0, 0]
	
	private func ok(_ visited: inout [[Bool]], _ t: Int, _ i: Int, _ j: Int) -> Bool {
		if i < 0 || j < 0 || i >= grid.count || j >= grid.count || visited[i][j] || grid[i][j] > t {
			return false
		}
		visited[i][j] = true
		for k in dx.indices {
			ok(&visited, t, i + dx[k], j + dy[k])
		}
		return visited.last?.last ?? false
	}
	
	func swimInWater(_ grid: [[Int]]) -> Int {
		self.grid = grid
		var (lo, hi, ans) = (0, 3000, 3000)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			var visited = [[Bool]](repeating: [Bool](repeating: false, count: grid.count), count: grid.count)
			if ok(&visited, mid, 0, 0) {
				ans = mid
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		}
		return ans
	}
}
