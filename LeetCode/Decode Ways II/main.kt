class Solution {
    private var dp = LongArray(0)
    private val mod = (1e9 + 7).toLong()

    private fun numDecodingsHelper(s: String, index: Int): Long {
        if (index == s.length) return 1L
        if (dp[index] != -1L) return dp[index]
        var ans = 0L
        when (s[index]) {
            '*' -> {
                ans = (ans + 9 * numDecodingsHelper(s, index + 1)) % mod
            }
            in '1'..'9' -> {
                ans = (ans + numDecodingsHelper(s, index + 1)) % mod
            }
        }
        if (index + 1 < s.length) {
            val (a, b) = listOf(s[index], s[index + 1])
            if (a == '2' && b == '*') {
                ans = (ans + 6 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '1' && b == '*') {
                ans = (ans + 9 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*' && b == '*') {
                ans = (ans + 15 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '2' && b <= '6') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '1') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*' && b <= '6') {
                ans = (ans + 2 * numDecodingsHelper(s, index + 2)) % mod;
            } else if (a == '*') {
                ans = (ans + numDecodingsHelper(s, index + 2)) % mod;
            }
        }
        dp[index] = ans
        return ans
    }

    fun numDecodings(s: String): Int {
        dp = LongArray(s.length) { -1L }
        return numDecodingsHelper(s, 0).toInt()
    }
}