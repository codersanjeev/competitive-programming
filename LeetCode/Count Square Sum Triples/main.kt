class Solution {
    fun countTriples(n: Int): Int {
        var ans = 0
        for (a in 1 until n + 1) {
            for (b in 1 until n + 1) {
                for (c in 1 until n + 1) {
                    if (a * a + b * b == c * c) {
                        ++ans
                    }
                }
            }
        }
        return ans
    }
}