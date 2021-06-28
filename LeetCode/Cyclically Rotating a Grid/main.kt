class Solution {
    fun rotateGrid(grid: Array<IntArray>, k: Int): Array<IntArray> {
        var (top, left, bottom, right) = listOf(0, 0, grid.size - 1, grid[0].size - 1)
        while (top < bottom && left < right) {
            var K = k % (2 * (bottom - top + 1) + 2 * (right - left + 1) - 4)
            while (K-- > 0) {
                val ele = grid[top][left]
                for (j in left until right) {
                    grid[top][j] = grid[top][j + 1]
                }
                for (i in top until bottom) {
                    grid[i][right] = grid[i + 1][right]
                }
                for (j in right downTo left + 1) {
                    grid[bottom][j] = grid[bottom][j - 1]
                }
                for (i in bottom downTo top + 1) {
                    grid[i][left] = grid[i - 1][left]
                }
                grid[top + 1][left] = ele
            }
            ++top
            ++left
            --bottom
            --right
        }
        return grid
    }
}