class Solution {
    fun maxScore(cardPoints: IntArray, k: Int): Int {
        var (ans, curr) = arrayOf(0, 0)
        for (i in 0 until k) {
            curr += cardPoints[i]
        }
        ans = curr
        var (i, j) = arrayOf(cardPoints.size - 1, k - 1)
        while (j >= 0) {
            curr -= cardPoints[j]
            curr += cardPoints[i]
            ans = ans.coerceAtLeast(curr)
            --j
            --i
        }
        return ans
    }
}
