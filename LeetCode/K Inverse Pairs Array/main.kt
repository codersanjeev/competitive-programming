class Solution {

    private var dp = Array(1001) { LongArray(1001) { 0L } }
    private val mod = (1e9 + 7).toLong()

    fun kInversePairs(n: Int, k: Int): Int {
        val pos = (n * (n - 1)).shr(1)
        if (k < 0 || k > pos) return 0
        if (k == 0 || k == pos) return 1
        if (dp[n][k] != 0L) return dp[n][k].toInt()
        val ans = kInversePairs(n, k - 1).toLong() +
                kInversePairs(n - 1, k).toLong() -
                kInversePairs(n - 1, k - n).toLong() + mod
        dp[n][k] = ans.rem(mod)
        return dp[n][k].toInt()
    }
}