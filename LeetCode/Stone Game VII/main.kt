class Solution {

    private var dp = ArrayList<IntArray>()

    private fun solve(stones: IntArray, i: Int, j: Int, score: Int): Int {
        if (i == j) return 0
        if (dp[i][j] != -1) return dp[i][j]
        val a = score - stones[i] - solve(stones, i + 1, j, score - stones[i])
        val b = score - stones[j] - solve(stones, i, j - 1, score - stones[j])
        dp[i][j] = a.coerceAtLeast(b)
        return dp[i][j]
    }

    fun stoneGameVII(stones: IntArray): Int {
        dp = ArrayList(
            generateSequence {
                IntArray(stones.size) { -1 }
            }.take(stones.size).toList()
        )
        return solve(stones, 0, stones.size - 1, stones.sum())
    }
}
