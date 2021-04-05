class Solution {
    fun countNegatives(grid: Array<IntArray>): Int {
        val n = grid.count()
        val m = grid[0].count()
        var ans = 0
        for (i in 0 until n) {
            var j = 0
            while (j < m) {
                if (grid[i][j] < 0) {
                    break
                }
                j++
            }
            ans += (m - j)
        }
        return ans
    }
}