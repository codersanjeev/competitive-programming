class Solution {
    private val mod = (1e9 + 7).toLong()

    private fun binpow(a: Long, b: Long): Long {
        var (x, y, ans) = listOf(a.rem(mod), b, 1L)
        while (y > 0) {
            if (y.rem(2L) == 1L) ans = (ans * x).rem(mod)
            x = (x * x).rem(mod)
            y /= 2
        }
        return ans
    }

    fun countGoodNumbers(n: Long): Int {
        val x = n / 2L
        val y = n - x
        return (binpow(4, x) * binpow(5, y)).rem(mod).toInt()
    }
}