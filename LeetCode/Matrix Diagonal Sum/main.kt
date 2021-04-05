class Solution {
    fun diagonalSum(mat: Array<IntArray>): Int {
        val n = mat.count()
        var ans = 0
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (i == j || i + j + 1 == n) {
                    ans += mat[i][j]
                }
            }
        }
        return ans
    }
}