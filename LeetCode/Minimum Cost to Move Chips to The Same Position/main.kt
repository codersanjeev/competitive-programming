class Solution {
    fun minCostToMoveChips(position: IntArray): Int {
        var x = 0
        var y = 0
        position.forEach { pos ->
            if (pos % 2 == 0) {
                x++
            } else {
                y++
            }
        }
        return Math.min(x, y)
    }
}