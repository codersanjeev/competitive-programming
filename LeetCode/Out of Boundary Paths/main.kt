class Solution {

    private val dx = listOf(0, 0, 1, -1)
    private val dy = listOf(1, -1, 0, 0)
    private val mod = 1000000007
    private val dp = generateSequence {
        generateSequence {
            generateSequence {
                -1
            }.take(51).toMutableList()
        }.take(51).toMutableList()
    }.take(51).toMutableList()

    fun findPaths(m: Int, 
                  n: Int, 
                  maxMove: Int, 
                  startRow: Int, 
                  startColumn: Int
    ): Int {
        if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) {
            return 1
        }
        if (maxMove == 0) return 0
        if (dp[maxMove][startRow][startColumn] != -1) {
            dp[maxMove][startRow][startColumn]
        }
        var ans = 0
        for (k in dx.indices) {
            ans = (ans + findPaths(m, 
                                   n, 
                                   maxMove - 1, 
                                   startRow + dx[k], 
                                   startColumn + dy[k]
            )).rem(mod)
        }
        dp[maxMove][startRow][startColumn] = ans
        return ans
    }
}