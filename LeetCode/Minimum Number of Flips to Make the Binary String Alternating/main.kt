class Solution {
    fun minFlips(s: String): Int {
        val arr = IntArray(2 * s.length)
        for (i in arr.indices) {
            arr[i] = (i % 2).xor(s[i % s.length] - '0')
        }
        var (zeros, ones) = arrayOf(0, 0)
        for (i in s.indices) {
            when (arr[i]) {
                0 -> ++zeros
                1 -> ++ones
            }
        }
        var (i, j, ans) = arrayOf(0, s.length, s.length)
        while (j < arr.size) {
            ans = ans.coerceAtMost(zeros)
            ans = ans.coerceAtMost(ones)
            when (arr[i++]) {
                0 -> --zeros
                1 -> --ones
            }
            when (arr[j++]) {
                0 -> ++zeros
                1 -> ++ones
            }
        }
        return ans
    }
}