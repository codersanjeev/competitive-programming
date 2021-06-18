import kotlin.math.abs
import kotlin.math.min

class Solution {
    private fun fill(s: String, ch: Char): Int {
        var answer = 0
        for (i in s.indices step 2) {
            if (s[i] != ch) ++answer
        }
        return answer
    }

    fun minSwaps(s: String): Int {
        val (N, ones) = arrayOf(s.length, s.count { it == '1' })
        val zeros = N - ones
        if (abs(zeros - ones) > 1) return -1
        val (x, y) = arrayOf(fill(s, '1'), fill(s, '0'))
        return when {
            ones > zeros -> x
            ones < zeros -> y
            else -> min(x, y)
        }
    }
}