class Solution {
    private lateinit var grid1: Array<IntArray>
    private lateinit var grid2: Array<IntArray>
    private var dx = listOf(0, 0, 1, -1)
    private var dy = listOf(1, -1, 0, 0)
    private var n = 0
    private var m = 0

    private fun dfs(i: Int, j: Int): Int {
        if (i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0) {
            return -1
        }
        if (grid1[i][j] == 0) return 0;
        grid2[i][j] = 0
        var res = 1
        for (k in dx.indices) {
            if (dfs(i + dx[k], j + dy[k]) == 0) {
                res = 0
            }
        }
        return res
    }

    fun countSubIslands(grid1: Array<IntArray>, grid2: Array<IntArray>): Int {
        this.grid1 = grid1
        this.grid2 = grid2
        n = grid2.size
        m = grid2[0].size
        var ans = 0
        for (i in grid2.indices) {
            for (j in grid2[0].indices) {
                if (dfs(i, j) == 1) ++ans
            }
        }
        return ans
    }
}