class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): BooleanArray {
        val curr = candies.max() ?: 0
        var ans: BooleanArray = BooleanArray(candies.count())
        var index = 0
        candies.forEach { candy ->
            if (candy + extraCandies >= curr) ans[index] = true
            index++
        }
        return ans
    }
}
