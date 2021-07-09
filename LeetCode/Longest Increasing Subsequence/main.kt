import kotlin.math.max

class Solution {
    fun lengthOfLIS(nums: IntArray): Int {
        val n = nums.size
        val dp = IntArray(n) { 1 }
        for (i in 1 until n) {
            for (j in 0 until i) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j])
                }
            }
        }
        return dp.max() ?: 1
    }
}