class Solution {
    fun heightChecker(heights: IntArray): Int {
        val sortedHeights = heights.sorted()
        val n = heights.count()
        var ans = 0
        for (i in 0 until n) {
            if (heights[i] != sortedHeights[i]) {
                ans++
            }
        }
        return ans
    }
}