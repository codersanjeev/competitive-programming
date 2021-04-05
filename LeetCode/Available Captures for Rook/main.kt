class Solution {
    fun numRookCaptures(board: Array<CharArray>): Int {
        var ans = 0; var x = 0; var y = 0
        for (i in 0 until 8) {
            for (j in 0 until 8) {
                if (board[i][j] == 'R') {
                    x = i
                    y = j
                }
            }
        }
        var dx = listOf<Int>(0, 0, 1, -1)
        var dy = listOf<Int>(-1, 1, 0, 0)
        for (k in 0 until 4) {
            var i = x; var j = y
            while (i >= 0 && j >= 0 && i < 8 && j < 8) {
                if (board[i][j] == 'p') {
                    ans++
                    break
                }
                if (board[i][j] != '.' && board[i][j] != 'R') {
                    break
                }
                i += dx[k]
                j += dy[k]
            }
        }
        return ans
    }
}