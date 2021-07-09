import kotlin.math.max

class Solution {
    fun findLength(A: IntArray, B: IntArray): Int {
        val (n, m) = listOf(A.size, B.size)
        val dp = Array(n + 1) { IntArray(m + 1) }
        for (i in n - 1 downTo 0) {
            for (j in m - 1 downTo 0) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1
                }
            }
        }
        var ans = 0
        for (row in dp) {
            for (ele in row) {
                ans = max(ans, ele)
            }
        }
        return ans
    }
}