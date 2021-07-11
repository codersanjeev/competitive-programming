class Solution {
	private func isSafe(_ i: Int, _ j: Int, _ m: Int, _ n: Int) -> Bool {
		return i >= 0 && j >= 0 && i < m && j < n
	}
	
	private func isBoundary(_ i: Int, _ j: Int, _ m: Int, _ n: Int) -> Bool {
		return i == 0 || j == 0 || i == m - 1 || j == n - 1
	}
	
	func nearestExit(_ maze: [[Character]], _ entrance: [Int]) -> Int {
		let dx = [0, 0, 1, -1]
		let dy = [1, -1, 0, 0]
		let (m, n) = (maze.count, maze[0].count)
		var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
		var q = [[Int]]()
		q.append([entrance[0], entrance[1], 0])
		visited[entrance[0]][entrance[1]] = true
		while !q.isEmpty {
			let curr = q.removeFirst()
			for k in 0 ..< 4 {
				let (nx, ny) = (curr[0] + dx[k], curr[1] + dy[k])
				if !isSafe(nx, ny, m, n) || visited[nx][ny] || maze[nx][ny] == Character("+") {
					continue
				}
				if isBoundary(nx, ny, m, n) && maze[nx][ny] == Character(".") && !visited[nx][ny] {
					return curr[2] + 1
				}
				if maze[nx][ny] == Character(".") && !visited[nx][ny] {
					visited[nx][ny] = true
					q.append([nx, ny, curr[2] + 1])
				}
			}
		}
		return -1
	}
}