import kotlin.math.abs

class Solution {
    fun findClosestElements(arr: IntArray, k: Int, x: Int): List<Int> {
        val ans = arr.sortedBy {
            abs(it - x)
        }
        return ans.take(k).sorted()
    }
}