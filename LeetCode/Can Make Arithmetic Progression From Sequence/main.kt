class Solution {
    fun canMakeArithmeticProgression(arr: IntArray): Boolean {
        val mx = arr.max() ?: 0
        var mn = arr.min() ?: 0
        val n = arr.count()
        if ((mx - mn) % (n - 1) != 0) {
            return false
        }
        val d = (mx - mn) / (n - 1)
        var idx = 0
        while (idx < n) {
            if (arr.contains(mn) == false) {
                return false
            }
            mn += d
            idx++
        }
        return true
    }
}