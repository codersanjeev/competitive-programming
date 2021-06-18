class Solution {
    private fun isGood(grid: Array<IntArray>, x: Int, y: Int, len: Int): Boolean {
        val st = HashSet<Int>()
        for (i in x until x + len) {
            var curr = 0
            for (j in y until y + len) curr += grid[i][j]
            st.add(curr)
        }
        for (j in y until y + len) {
            var curr = 0
            for (i in x until x + len) curr += grid[i][j]
            st.add(curr)
        }
        if (st.size > 1) return false
        var (i, j, curr) = arrayOf(x, y, 0)
        while (i < x + len && j < y + len) {
            curr += grid[i][j]
            ++i
            ++j
        }
        st.add(curr)
        if (st.size > 1) return false
        i = x; j = y + len - 1; curr = 0
        while (i < x + len && j >= y) {
            curr += grid[i][j]
            ++i
            --j
        }
        st.add(curr)
        return st.size == 1
    }

    private fun solve(grid: Array<IntArray>, n: Int, m: Int): Int {
        for (len in n downTo 1) {
            for (i in 0 until n - len + 1) {
                for (j in 0 until m - len + 1) {
                    if (isGood(grid, i, j, len)) return len
                }
            }
        }
        return 1
    }

    fun largestMagicSquare(grid: Array<IntArray>): Int {
        val (n, m) = arrayOf(grid.size, grid[0].size)
        return if (n < m) {
            solve(grid, n, m)
        } else {
            val arr = Array(m) { IntArray(n) }
            for (i in grid.indices) {
                for (j in grid[0].indices) {
                    arr[j][i] = grid[i][j]
                }
            }
            solve(arr, m, n)
        }
    }
}
