class Solution {
	
	private var ans = [[String]]()
	
	private func isSafe(_ board: [[Character]], _ row: Int, _ col: Int, _ n: Int) -> Bool {
		for i in 0 ..< row {
			if board[i][col] == "Q" {
				return false
			}
		}
		var (i, j) = (row - 1, col - 1)
		while (i >= 0 && j >= 0) {
			if board[i][j] == "Q" {
				return false
			}
			i -= 1
			j -= 1
		}
		i = row - 1
		j = col + 1
		while (i >= 0 && j < n) {
			if board[i][j] == "Q" {
				return false
			}
			i -= 1
			j += 1
		}
		return true
	}
	
	private func solve(_ board: inout [[Character]], _ row: Int, _ n: Int) {
		if row == n {
			var curr = [String]()
			board.forEach { curr.append(String($0)) }
			ans.append(curr)
			return
		}
		for col in 0 ..< n {
			if isSafe(board, row, col, n) {
				board[row][col] = "Q"
				solve(&board, row + 1, n)
				board[row][col] = "."
			}
		}
	}
	func totalNQueens(_ n: Int) -> Int {
		var board = [[Character]](repeating: [], count: n)
		for i in 0 ..< n {
			board[i] = [Character](repeating: ".", count: n)
		}
		solve(&board, 0, n)
		return ans.count
	}
}
