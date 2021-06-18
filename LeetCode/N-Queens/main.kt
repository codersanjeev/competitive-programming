class Solution {
    private var ans = mutableListOf<List<String>>()

    private fun isSafe(board: Array<CharArray>, row: Int, col: Int, n: Int): Boolean {
        for (i in 0 until row) {
            if (board[i][col] == 'Q') return false
        }
        var (i, j) = arrayOf(row - 1, col - 1)
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false
            --i
            --j
        }
        i = row - 1
        j = col + 1
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false
            --i
            ++j
        }
        return true
    }

    private fun solve(board: Array<CharArray>, row: Int, n: Int) {
        if (row == n) {
            val res = mutableListOf<String>()
            for (row in board) res.add(String(row))
            ans.add(res)
            return
        }
        for (col in 0 until n) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q'
                solve(board, row + 1, n)
                board[row][col] = '.'
            }
        }
    }

    fun solveNQueens(n: Int): List<List<String>> {
        val board = Array(n) { CharArray(n) { '.' } }
        solve(board, 0, n)
        return ans
    }
}