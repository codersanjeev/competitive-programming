class Solution {
    fun minDistance(s: String, t: String): Int {
        val (n, m) = arrayOf(s.length, t.length)
        val dp = Array(n + 1) { IntArray(m + 1) { 0 } }
        for (i in 1..n) {
            for (j in 1..m) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
                }
            }
        }
        return n + m - 2 * dp[n][m]
    }
}