class Solution {
    private lateinit var grid: Array<IntArray>
    private val dx = listOf(0, 0, 1, -1)
    private val dy = listOf(1, -1, 0, 0)

    private fun ok(visited: Array<BooleanArray>, t: Int, i: Int, j: Int): Boolean {
        if (i < 0 || j < 0 || i >= grid.size || j >= grid.size || visited[i][j] || grid[i][j] > t) {
            return false
        }
        visited[i][j] = true
        for (k in dx.indices) {
            ok(visited, t, i + dx[k], j + dy[k])
        }
        return visited.last().last()
    }

    fun swimInWater(grid: Array<IntArray>): Int {
        this.grid = grid
        var (lo, hi, ans) = arrayOf(0, grid.size * grid.size, grid.size * grid.size)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            val visited = Array(grid.size) { BooleanArray(grid.size) { false } }
            if (ok(visited, mid, 0, 0)) {
                ans = mid
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        return ans
    }
}
