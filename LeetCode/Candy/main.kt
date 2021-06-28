import kotlin.math.max

class Solution {
    fun candy(ratings: IntArray): Int {
        var ans = IntArray(ratings.size) { 1 }
        for (i in 1 until ratings.size) {
            if (ratings[i - 1] < ratings[i]) {
                ans[i] = 1 + ans[i - 1]
            }
        }
        for (i in ratings.size - 1 downTo 1) {
            if (ratings[i - 1] > ratings[i]) {
                ans[i - 1] = max(ans[i - 1], 1 + ans[i])
            }
        }
        return ans.sum()
    }
}