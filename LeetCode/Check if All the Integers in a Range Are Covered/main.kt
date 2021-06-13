class Solution {
    fun isCovered(ranges: Array<IntArray>, left: Int, right: Int): Boolean {
        val visited = BooleanArray(51)
        for (range in ranges) {
            for (i in range[0]..range[1]) {
                visited[i] = true
            }
        }
        for (i in left..right) {
            if (visited[i] == false) {
                return false
            }
        }
        return true
    }
}
