class Solution {
    fun findTheDistanceValue(arr1: IntArray, arr2: IntArray, d: Int): Int {
        var ans = 0
        arr1.forEach { x ->
            var good = true
            arr2.forEach { y ->
                if (Math.abs(x - y) <= d) {
                    good = false
                }
            }
            if (good) {
                ans++
            }
        }
        return ans
    }
}