class Solution {
    fun maximumGap(nums: IntArray): Int {
        if (nums.size < 2) return 0
        val (mx, mn) = arrayOf(nums.max()!!, nums.min()!!)
        val bucket = (mx - mn).toDouble() / (nums.size - 1).toDouble()
        val maxElement = IntArray(nums.size) { Int.MIN_VALUE }
        val minElement = IntArray(nums.size) { Int.MAX_VALUE }
        for (i in nums.indices) {
            val index = if (bucket == 0.0) 0 else ((nums[i] - mn) / bucket).toInt()
            maxElement[index] = maxElement[index].coerceAtLeast(nums[i])
            minElement[index] = minElement[index].coerceAtMost(nums[i])
        }
        var (ans, previous) = arrayOf(0, maxElement[0])
        for (i in 1 until nums.size) {
            if (minElement[i] == Int.MAX_VALUE) continue
            ans = ans.coerceAtLeast(minElement[i] - previous)
            previous = maxElement[i]
        }
        return ans
    }
}