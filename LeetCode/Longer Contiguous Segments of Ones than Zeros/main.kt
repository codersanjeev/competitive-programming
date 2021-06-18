class Solution {
    private fun count(s: String, ch: Char): Int {
        val dp = MutableList(s.length) { 0 }
        if (s[0] == ch) dp[0] = 1
        for (i in 1 until s.length) {
            if (s[i] == ch) {
                dp[i] = if (s[i] == s[i - 1]) dp[i - 1] + 1 else 1
            }
        }
        return Collections.max(dp)
    }

    fun checkZeroOnes(s: String): Boolean {
        return count(s, '1') > count(s, '0')
    }
}