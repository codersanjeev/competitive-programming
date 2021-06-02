class Solution {
    fun isInterleave(x: String, y: String, z: String): Boolean {
        if (x.length + y.length != z.length) return false
        val dp = Array(x.length + 1) { BooleanArray(y.length + 1) { false } }
        dp[0][0] = true
        for (i in 1..x.length) {
            dp[i][0] = dp[i - 1][0] && (x[i - 1] == z[i - 1])
        }
        for (j in 1..y.length) {
            dp[0][j] = dp[0][j - 1] && (y[j - 1] == z[j - 1])
        }
        for (i in 1..x.length) {
            for (j in 1..y.length) {
                dp[i][j] =
                    (dp[i - 1][j] && x[i - 1] == z[i + j - 1]) 
                    || (dp[i][j - 1] && y[j - 1] == z[i + j - 1])
            }
        }
        return dp[x.length][y.length]
    }
}