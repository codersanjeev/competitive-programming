class Solution {
    fun minCostClimbingStairs(cost: IntArray): Int {
        val dp = IntArray(cost.size + 1)
        for (i in 2 until dp.size) {
            dp[i] = (dp[i - 1] + cost[i - 1]).coerceAtMost(dp[i - 2] + cost[i - 2])
        }
        return dp.last()
    }
}