class Solution {
    fun matrixReshape(mat: Array<IntArray>, r: Int, c: Int): Array<IntArray> {
        val (n, m) = listOf(mat.size, mat[0].size)
        if (n * m != r * c) return mat
        val temp = mutableListOf<Int>()
        for (row in mat) {
            for (ele in row) {
                temp.add(ele)
            }
        }
        val ans = Array(r) { IntArray(c) }
        var k = 0
        for (i in ans.indices) {
            for (j in ans[0].indices) {
                ans[i][j] = temp[k]
                ++k
            }
        }
        return ans
    }
}