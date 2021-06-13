class Solution {
    private var grid = [[Int]]()
    
	private func isGood(_ x: Int, _ y: Int, _ len: Int) -> Bool {
		var st = Set<Int>()
		for i in stride(from: x, to: x + len, by: 1) {
			var curr = 0
			for j in stride(from: y, to: y + len, by: 1) { curr += grid[i][j] }
			st.insert(curr)
		}
		for j in stride(from: y, to: y + len, by: 1) {
			var curr = 0
			for i in stride(from: x, to: x + len, by: 1) { curr += grid[i][j] }
			st.insert(curr)
		}
		if st.count > 1 { return false }
		var (i, j, curr) = (x, y, 0)
		while i < x + len && j < y + len {
			curr += grid[i][j]
			i += 1
			j += 1
		}
		st.insert(curr)
		if st.count > 1 { return false }
		(i, j, curr) = (x, y + len - 1, 0)
		while i < x + len && j >= y {
			curr += grid[i][j]
			i += 1
			j -= 1
		}
		st.insert(curr)
 		return st.count == 1
	}
	
	private func solve(_ n: Int, _ m: Int) -> Int {
		for len in stride(from: n, to: 1, by: -1) {
			for i in stride(from: 0, to: n - len + 1, by: 1) {
				for j in stride(from: 0, to: m - len + 1, by: 1) {
					if isGood(i, j, len) {
						return len
					}
				}
			}
		}
		return 1
	}

	func largestMagicSquare(_ g: [[Int]]) -> Int {
		let (n, m) = (g.count, g[0].count)
		if n < m {
            grid = g
			return solve(n, m)
		} else {
			grid = [[Int]](repeating: [Int](repeating: 0, count: n), count: m)
			for i in stride(from: 0, to: n, by: 1) {
				for j in stride(from: 0, to: m, by: 1) {
					grid[j][i] = g[i][j]
				}
			}
			return solve(m, n)
		}
	}
}
