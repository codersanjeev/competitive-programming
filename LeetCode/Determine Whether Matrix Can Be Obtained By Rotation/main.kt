class Solution {
    fun findRotation(mat: Array<IntArray>, target: Array<IntArray>): Boolean {
        for (i in 0 until 4) {
            if (areMatrixEqual(mat, target)) return true
            rotate(mat)
        }
        return false
    }

    private fun rotate(matrix: Array<IntArray>) {
        val len = matrix.size
        for (i in 0 until len) {
            for (j in 0 until i) {
                val temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
            }
        }
        for (i in 0 until len) {
            matrix[i] = matrix[i].reversed().toIntArray()
        }
    }

    private fun areMatrixEqual(x: Array<IntArray>, y: Array<IntArray>): Boolean {
        for (i in x.indices) {
            for (j in x.indices) {
                if (x[i][j] != y[i][j]) return false
            }
        }
        return true
    }
}