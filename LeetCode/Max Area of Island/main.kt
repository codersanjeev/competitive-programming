class Solution {
    private var dx = arrayOf(0, 0, 1, -1)
    private var dy = arrayOf(1, -1, 0, 0)

    private fun dfs(grid: Array<IntArray>, i: Int, j: Int): Int {
        if (i < 0 || j < 0 || i >= grid.size || j >= grid[0].size || grid[i][j] != 1) {
            return 0
        }
        grid[i][j] = -1
        var ans = 1
        for (k in 0..3) {
            ans += dfs(grid, i + dx[k], j + dy[k])
        }
        return ans
    }

    fun maxAreaOfIsland(grid: Array<IntArray>): Int {
        var ans = 0
        for (i in grid.indices) {
            for (j in grid[0].indices) {
                if (grid[i][j] == 1) {
                    ans = ans.coerceAtLeast(dfs(grid, i, j))
                }
            }
        }
        return ans
    }
}