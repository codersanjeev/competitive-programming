class Solution {
    fun maximumUnits(boxTypes: Array<IntArray>, t: Int): Int {
        boxTypes.sortByDescending { it[1] }
        var (ans, truckSize) = arrayOf(0, t)
        for (boxType in boxTypes) {
            if (truckSize <= 0) break
            val curr = truckSize.coerceAtMost(boxType[0])
            ans += boxType[1] * curr
            boxType[0] -= curr
            truckSize -= curr
        }
        return ans
    }
}