class Solution {
    fun generate(numRows: Int): List<List<Int>> {
        val ans = ArrayList<ArrayList<Int>>()
        val curr = ArrayList<Int>()
        for (i in 0 until numRows) {
            curr.add(0, 1)
            for (j in 1 until curr.size - 1) {
                curr[j] = curr[j] + curr[j + 1]
            }
            ans.add(ArrayList(curr))
        }
        return ans
    }
}