class Solution {
    fun luckyNumbers (matrix: Array<IntArray>): List<Int> {
        var n = matrix.count()
        var m = matrix[0].count()
        var x = Integer.MIN_VALUE
        var y = Integer.MAX_VALUE
        for (i in 0 until n) {
            var curr = Integer.MAX_VALUE
            for (j in 0 until m) {
                curr = Math.min(curr, matrix[i][j])
            }
            x = Math.max(x, curr)
        }
        for (j in 0 until m) {
            var curr = Integer.MIN_VALUE
            for (i in 0 until n) {
                curr = Math.max(curr, matrix[i][j])
            }
            y = Math.min(y, curr)
        }
        if (x != y) {
            return emptyList<Int>()
        } else {
            return listOf(x)
        }
    }
}