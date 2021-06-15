class Solution {
    private var squareSide = 0

    private fun makesquareRecursive(matchsticks: IntArray, index: Int, square: IntArray): Boolean {
        if (index == matchsticks.size) {
            return square.toSet().size == 1
        }
        for (i in 0 until 4) {
            square[i] += matchsticks[index]
            if (square[i] <= this.squareSide && makesquareRecursive(
                    matchsticks,
                    index + 1,
                    square
                )
            ) {
                return true
            }
            square[i] -= matchsticks[index]
        }
        return false
    }

    fun makesquare(matchsticks: IntArray): Boolean {
        val sum = matchsticks.sum()
        if (sum % 4 != 0) return false
        this.squareSide = sum / 4
        val square = IntArray(4) { 0 }
        matchsticks.sortDescending()
        return makesquareRecursive(matchsticks, 0, square)
    }
}
