class Solution {
    fun rotate(matrix: Array<IntArray>) {
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
}
