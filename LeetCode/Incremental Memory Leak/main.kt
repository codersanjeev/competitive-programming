class Solution {
    fun memLeak(memory1: Int, memory2: Int): IntArray {
        var (x, y, t) = arrayOf(memory1, memory2, 0)
        while (true) {
            when {
                x >= y -> {
                    if (t > x) return intArrayOf(t, x, y)
                    x -= t
                }
                x < y -> {
                    if (t > y) return intArrayOf(t, x, y)
                    y -= t
                }
            }
            t += 1
        }
        return IntArray(0)
    }
}