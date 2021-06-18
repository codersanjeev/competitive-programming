class Solution {
    fun stoneGameVIII(stones: IntArray): Int {
        for (i in 1 until stones.size) {
            stones[i] += stones[i - 1]
        }
        return solve(stones, 0)
    }

    private fun solve(stones: IntArray, index: Int): Int {
        if (index == stones.size - 2) return stones.last()
        val next = solve(stones, index + 1)
        return next.coerceAtLeast(stones[index + 1] - next)
    }
}