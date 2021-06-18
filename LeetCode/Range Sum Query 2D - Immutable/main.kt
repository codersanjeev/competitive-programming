class NumMatrix(matrix: Array<IntArray>) {

    private lateinit var prefixSum: Array<IntArray>

    init {
        val (n, m) = arrayOf(matrix.size, matrix[0].size)
        prefixSum = Array(n + 1) { IntArray(m + 1) { 0 } }
        for (i in 1..n) {
            for (j in 1..m) {
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i][j - 1]
            }
        }
        for (j in 1..m) {
            for (i in 1..n) {
                prefixSum[i][j] += prefixSum[i - 1][j]
            }
        }
    }

    fun sumRegion(si: Int, sj: Int, ei: Int, ej: Int): Int {
        return prefixSum[ei + 1][ej + 1] - prefixSum[ei + 1][sj] - prefixSum[si][ej + 1] + prefixSum[si][sj]
    }
}