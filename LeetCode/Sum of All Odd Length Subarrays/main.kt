class Solution {
    fun sumOddLengthSubarrays(arr: IntArray): Int {
        val n = arr.count()
        var ans = 0
        for (i in 0 until n) {
            ans += (((i + 1) * (n - i) + 1) / 2) * arr[i]
        }
        return ans
    }
}