class Solution {
    fun longestStrChain(words: Array<String>): Int {
        if (words.size < 2) return words.size
        words.sortBy { it.length }
        val dp = MutableList(words.size) { 1 }
        for (i in 1 until words.size) {
            for (j in 0 until i) {
                if (words[i].isPredecessor(words[j])) {
                    dp[i] = dp[i].coerceAtLeast(1 + dp[j])
                }
            }
        }
        return dp.max() ?: 0
    }

    private fun String.isPredecessor(x: String): Boolean {
        val y = this
        if (y.length - x.length != 1) return false
        if (y.substring(1) == x || y.substring(0, x.length) == x) {
            return true
        }
        for (i in 0 until y.length - 1) {
            if (y.substring(0, i) + y.substring(i + 1) == x) {
                return true
            }
        }
        return false
    }
}