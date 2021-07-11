class Solution {
    fun sumGame(num: String): Boolean {
        val n = num.length
        var (x, y) = listOf(0.0, 0.0)
        for (i in num.indices) {
            var a = 4.5
            if (num[i] != '?') a = (num[i] - '0').toDouble()
            if (i < n / 2) {
                x += a
            } else {
                y += a
            }
        }
        return x != y
    }
}