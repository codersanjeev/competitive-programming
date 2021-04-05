class Solution {
    fun oddCells(n: Int, m: Int, indices: Array<IntArray>): Int {
        var arr = Array(n) { IntArray(m) { 0 } }
        indices.forEach { (x, y) ->
            for (i in 0 until n) {
                arr[i][y]++
            }
            for (j in 0 until m) {
                arr[x][j]++
            }
        }
        var ans = 0
        arr.forEach { row ->
            row.forEach { ele -> 
                if (ele % 2 == 1) {
                    ans++
                }
            }
        }
        return ans
    }
}