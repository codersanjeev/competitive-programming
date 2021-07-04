class Solution {
    fun countVowelPermutation(n: Int): Int {
        val mod = (1e9 + 7).toLong()
        val dp = Array(n) { LongArray(5) { 1L } }
        for (i in 1 until n) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]).rem(mod)
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]).rem(mod)
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]).rem(mod)
            dp[i][3] = dp[i - 1][2]
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]).rem(mod)
        }
        var ans = 0L
        for (ele in dp[n - 1]) ans = (ans + ele).rem(mod)
        return ans.rem(mod).toInt()
    }
}